#include<stdio.h>
#include<queue>
#define MaxSize 15

using namespace std;

struct node{
    int LChild;
    int RChild;
}Node[MaxSize];

int n, lnum = 0, num = 0;   //num表示已打出的结点数，lnum表示叶结点的总数
bool notRoot[MaxSize] = {false};
bool notLeaves[MaxSize] = {false};

int strToNum(char c){
    if(c == '-'){
        return -1;
    }else{
        notRoot[c - '0'] = true;
        return c - '0';
    }
}

int FindRoot(node Node[], int n){
    for(int i = 0; i < n; i++){
        if(notRoot[i] == false){
            return i;
        }
    }
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    
    while(!q.empty()){
        int now = q.front();
        if(Node[now].LChild == -1 && Node[now].RChild == -1){
            printf("%d", now);
            if(num < lnum - 1) printf(" ");
            num++;
        }
        q.pop();
        if(Node[now].LChild != -1) q.push(Node[now].LChild);
        if(Node[now].RChild != -1) q.push(Node[now].RChild);
    }
}


int main(){
    scanf("%d", &n);

    int lchild, rchild;
    for(int i = 0; i < n; i++){
        scanf("%*c%c %c", &lchild, &rchild);
        Node[i].LChild = strToNum(lchild);
        Node[i].RChild = strToNum(rchild);
    }

    int root = FindRoot(Node, n);

    //用于确定叶子结点
    for(int i = 0; i < n; i++){
        if(Node[i].LChild == -1 && Node[i].RChild == -1){
            notLeaves[i] = true;
            lnum++;
        }
    }

    BFS(root);

    return 0;
}
