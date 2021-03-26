#include<stdio.h>
//#include<algorithm>
#include<queue>

/*
题意是根据后序遍历和中序遍历创建的树，输出层次遍历的结果
关键是找根结点
1)首先是后序遍历的最后一个数必是根结点；然后到中序遍历中找到那个结点
2)找到结点后，输出中序遍历左子树的个数，在后序遍历上找到对应数目的结点，末尾结点就是左子树的根结点
3)以此类推
具体实现步骤有创建树和进行层序遍历
*/

#define ElementType int
using namespace std;

struct node{
    ElementType Data;
    node* LChild;
    node* RChild;
};

int n;
int post[35], in[35];   //用于存放结点

node* Create(int postl, int postr, int inl, int inr){
    if(postl > postr){
        return NULL;
    }

    node* root = new node;
    root->Data = post[postr];   //后序遍历的最后一个数就是根结点

    //在中序遍历中找到根结点
    int i;
    for(i = 0; i < inr; i++){
        if(in[i] == post[postr]){
            break;
        }
    }
    
    int left = i - inl; //左子树的个数
    root->LChild = Create(postl, postl + left - 1, inl, i - 1); //递归找出左子树的根结点
    root->RChild = Create(postl + left, postr - 1, i + 1, inr);

    return root;
}

int num = 0;    //表示打印出的元素个数

void BFS(node* root){   //层序遍历需要使用队列
    queue<node*> q; //注意队列里存的是地址
    q.push(root);

    while(!q.empty()){
        node* now = q.front();  //获得队首元素
        q.pop();       //弹出
        printf("%d", now->Data);
        num++;
        if(num < n){
            printf(" ");
        }

        if(now->LChild != NULL) q.push(now->LChild);
        if(now->RChild != NULL) q.push(now->RChild);
    }
}

int main(){
    //int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }

    //创建树
    node* root = Create(0, n - 1, 0, n - 1);

    //打印层次遍历的树
    BFS(root);

    return 0;
}
