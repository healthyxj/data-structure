#include<stdio.h>
#include<queue>
/*
题意：根据结点数和结点的状态，建立二叉树。然后将二叉树左右翻转，输出层序遍历和中序遍历的结果
层序遍历使用队列；因为直接给出了结点编号之间的关系，可以直接插入左右儿子结点，但是需要找到根结点。
因为使用的是编号作为树的结点，所以可以使用静态树。
*/
using namespace std;

#define MaxSize 15

struct node{
    int LChild;
    int RChild;
}Node[MaxSize];

//node Node[MaxSize];
bool notRoot[MaxSize] = {false};    //要使用bool类型
int n;
//int tmp = 0;

//将符号转为数字，并且在过程中对是否为根结点作标记
int strToNum(char c){
    if(c == '-'){
        return -1;
    }else{
        //tmp++;
        notRoot[c - '0'] = true;
        return c - '0';
    }
}

int num = 0;    //记录打印的结点个数
void print(int root){   //最好就填root，否则容易引起参数混乱
    if(root == -1){
        return ;
    }else{
        printf("%d", root);
        num++;
        if(num < n){
            printf(" ");
        }else{
            printf("\n");
        }
        
    }
}

//用于找出根结点
int FindRoot(node Node[], int n){
    for(int i = 0; i < n; i++){
        if(notRoot[i] == false){
            return i;
        }
    }
}

//后序遍历，对树进行翻转
void PostOrder(int root){
    if(root == -1){
        return ;
    }else{
        PostOrder(Node[root].LChild);
        PostOrder(Node[root].RChild);
        swap(Node[root].LChild, Node[root].RChild);
    }

}

//层序遍历
void LevelOrder(int root){
    queue<int> q;
    q.push(root);
    
    while(!q.empty()){
        int now = q.front();
        print(now);

        q.pop();
        
        if(Node[now].LChild != -1) q.push(Node[now].LChild);
        if(Node[now].RChild != -1) q.push(Node[now].RChild);
    }

}

//中序遍历
void InOrder(int root){
    if(root == -1){
        return ;
    }else{
        InOrder(Node[root].LChild);
        print(root);
        InOrder(Node[root].RChild);
    }
}

int main(){
    char lchild, rchild;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%*c%c %c", &lchild, &rchild);    //需要对换行进行特殊处理
        Node[i].LChild = strToNum(lchild);
        Node[i].RChild = strToNum(rchild);
    }

    int root = FindRoot(Node, n);   //这里是Node,不是Node[]

    PostOrder(root);

    LevelOrder(root);

    num = 0;    //之前将num增加到n，这里需要对num进行重置
    InOrder(root);

    return 0;
}
