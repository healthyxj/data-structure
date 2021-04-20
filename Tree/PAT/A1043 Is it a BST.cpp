#include<stdio.h>
#include<vector>

using namespace std;

/*
用给定的序列构造出二叉排序树，然后检测插入的序列是否是先序序列or镜像树的先序序列，
*/

struct node{
    int Data;
    node *Left;
    node *Right;
};

//插入结点, 函数三要数：函数名, 参数列表(这里需要改变，故使用&), 返回值
void insert(node* &root, int data){ //这里填的是地址，所以使用&; *是使用node带来的
    if(root == NULL){
        root = new node;    //需要申请新的结点
        root->Data = data;
        root->Left = NULL;
        root->Right = NULL;
        return ;
    }
    
    if(root->Data > data){
        insert(root->Left, data);
    }else{
        insert(root->Right, data);
    }
}

//进行先序遍历，结果存放在vi中(因为需要比较)
void preOrder(node* root, vector<int>&vi){  //先序遍历，结果存在vi中
    if(root == NULL) return ;
    
    vi.push_back(root->Data); //vector输出值
    preOrder(root->Left, vi);
    preOrder(root->Right, vi);
}

//进行镜像树的先序遍历,结果存在vi中
void preOrderM(node* root, vector<int>&vi){
    if(root == NULL) return ;
    
    vi.push_back(root->Data);
    preOrderM(root->Right, vi);
    preOrderM(root->Left, vi);
}

void postOrder(node* root, vector<int>&vi){
    if(root == NULL) return ;
    
    postOrder(root->Left, vi);
    postOrder(root->Right, vi);
    vi.push_back(root->Data);
}

void postOrderM(node* root, vector<int>&vi){
    if(root == NULL) return ;
    
    postOrderM(root->Right, vi);
    postOrderM(root->Left, vi);
    vi.push_back(root->Data);
}

//origin存放原始序列
vector<int> origin, post, postM, pre, preM;

int main(){
    int i, n, data;
    scanf("%d", &n);
    
    node* root = NULL;
    
    for(i = 0; i < n; i++){
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    
    preOrder(root, pre);
    preOrderM(root, preM);
    postOrder(root, post);
    postOrderM(root, postM);
    
    if(origin == pre){
        printf("YES\n");
        
        for(i = 0; i < post.size(); i++){
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    }else if(origin == preM){
        printf("YES\n");
        
        for(i = 0; i < postM.size(); i++){
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    }else{
        printf("NO\n");
    }
    
    return 0;
}
