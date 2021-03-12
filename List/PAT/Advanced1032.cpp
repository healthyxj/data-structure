#include<stdio.h>
#include<string.h>
/*
1、题目的范围不是很大，可以考虑使用静态链表。
2、题目要求给出了当前地址和下一个结点的地址，因此可以考虑将结点的当前地址作为静态链表的下标。
3、题目要求给出公用结点的地址，因此可以考虑设置一个flag，遇到这个结点就进行标记。
如果在第二次遍历的时候遇到了，就说明有公共结点。
4、因为存储的是字符，需要注意一些问题。比如读取原链表的时候，%c能够读入空格，所以需要%d %c %d
5、输出的时候，地址可能不是五位数，需要强制转化
*/

const int MaxSize = 100010;
typedef struct LNode{
    int Next;
    char Data;
    bool flag;
}Node[MaxSize];

int main(){
    int begin1, begin2, N;
    scanf("%d%d%d",&begin1, &begin2, &N);


    LNode L[MaxSize];

    for(int i = 0; i < MaxSize; i++){
        L[i].flag = false;  //注意：这里只能是.而不能用-> !!!!!!!!!!!!!
    }

    int p, q;
    char c1;
    for(int i = 0; i < N; i++){
        scanf("%d %c %d",&p, &c1, &q);
        L[p].Data = c1;
        L[p].Next = q;
    }

    int tmp = begin1;
    while(L[tmp].Next != -1){
        L[tmp].flag = true;
        tmp = L[tmp].Next;
    }

    tmp = begin2;
    while(tmp != -1){   //注意：可能一开始的结点就是-1！！！！！！！！！！
        if(L[tmp].flag == true){
            printf("%05d\n",tmp);
            break;
        }
        tmp = L[tmp].Next;
    }

    if(tmp == -1){
        printf("-1\n");
    }


    return 0;
}
