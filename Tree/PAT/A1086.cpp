#include<stdio.h>
#include<stack>
#include<string.h>
/*
题意是中序遍历可以使用栈来实现，这样就可以不使用递归。目标是给出后序遍历，末尾没有空格
Push后跟的是先序，pop是中序。
也就是用先序和中序创建树，然后
*/

using namespace std;
struct node{
    int Data;
    node* LChild;
    node* RChild;
};

int n;
int pre[35], in[35];

node* Create(int prel, int prer, int inl, int inr){
    if(prel > prer){
        return NULL;
    }

    int i = 0;
    for(i = inl; i <= inr; i++){
        if(in[i] == pre[prel]){
            break;
        }
    }

    node* root = new node;
    root->Data = pre[prel];

    int leftnum = i - inl;
    root->LChild = Create(prel + 1, prel + leftnum, inl, i - 1);
    root->RChild = Create(prel + 1 + leftnum, prer, i + 1, inr);

    return root;
}

int num = 0;
void PostOrder(node* root){
    if(root == NULL){
        return ;
    }

    PostOrder(root->LChild);
    PostOrder(root->RChild);
    printf("%d", root->Data);
    num++;
    if(num < n) printf(" ");    //这里总是忘记

}

int main(){
    scanf("%d", &n);
    //string tmp;没有这个类型
    char tmp[5];    //用char数组储存Push和Pop
    int j1 = 0, j2 = 0, k1 = 0;
    stack<int> st;

    for(int i = 0; i < 2 * n; i++){
        scanf("%s", tmp);   //不需要&
        if(strcmp(tmp, "Push") == 0){  //正常是比较地址值，strcmp相同返回0
            scanf("%d", &k1);
            pre[j1++] = k1;
            st.push(k1);
        }else{
            in[j2++] = st.top();
            st.pop();
        }
    }

    node* root = Create(0, n - 1, 0, n - 1);

    PostOrder(root);
    printf("\n");

    return 0;
}


