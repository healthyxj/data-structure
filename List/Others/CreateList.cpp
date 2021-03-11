#include<stdio.h>
#include<stdlib.h>

#define ElemType int  //这是将ElemType定义成int变量，如果是字符可以修改int为char
#define MaxSize 100

/*
该程序用于根据输入的数创建链表
输入格式
x x代表链表元素的个数
a b c d e f 分别代表输入元素的值
输出结果将是a b c d e f
*/

struct LNode{
    ElemType Data;  //定义数据域
    LNode* Next;  //定义指针域，注意是结点*，定义指针*不能漏
};

LNode* Create(int Array[], int n){  //注意创建链表需要用到*，数组作为参数的形式也需要注意
    LNode *head, *pre, *p;  //定义结点需要用到*

    head = (LNode*)malloc(sizeof(LNode)); //创建头结点需要申请空间；前面是指针的形式，后面不需要*
    head->Next = NULL;  //创建头结点后需要将Next指针赋值为NULL
    pre = head; //新定义一个指针用于插入元素

    for(int i = 0; i < n; i++){
        p = (LNode*)malloc(sizeof(LNode));  //插入元素需要新申请一块空间
        p->Data = Array[i]; 
        p->Next = NULL; //因为是尾插法，需要将Next指针赋值为NULL
        pre->Next = p;  //移动指示的指针
        pre = p;
    }

    return head;  //注意返回的是头结点
}

int main(){
    int n,a[MaxSize];
    scanf("%d", &n);
    LNode *p;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    p = Create(a, n); //注意数组的传参方式
    p = p->Next;  //将p指针后移一位，否则会输出头指针的地址
    while(p){
        printf("%d ", p->Data);
        p = p->Next;
    }

    return 0;
}
