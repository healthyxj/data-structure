#include<stdio.h>
#include<cstring>
#include<algorithm>

/*
对于给定地址、需要排序、且范围较小的题目，通常可以使用c++里的库来完成
1、定义静态链表，结点的出现与否用flag来定义
*/

using namespace std;

#define MaxSize 100010

struct Node{
    int Address, Next, Data;
    bool flag;
}node[MaxSize];

bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;   //只要a和b中有一个为无效结点，就放到后面
    }else{
        return a.Data < b.Data;   //若都为有效结点，就按照题目要求从小到大排序
    }
}

int main(){
    
    
    //2、初始化，表示开始时，所有结点都是无效结点
    for(int i = 0; i < MaxSize; i++){
        node[i].flag = false;
    }

    int N, begin, addr;
    scanf("%d%d",&N, &begin);

    for(int i = 0; i < N; i++){
        scanf("%d",&addr);
        scanf("%d%d",&node[addr].Data, &node[addr].Next);
        node[addr].Address = addr;
    }

    //3、对flag进行标记，同时记录有效结点的个数    注意可能会存在无效结点
    int count = 0,  p = begin;
    while(p != -1){
        node[p].flag = true;
        count++;
        p = node[p].Next;
    }

    //根据有效结点的数目输出
    if(count == 0){
        printf("0 -1");
    }else{
        //4、调用algorithm中的sort函数
        sort(node, node + MaxSize, cmp);
        printf("%d %05d\n",count,node[0].Address);
        for(int i = 0; i < count; i++){
            if(i != count - 1){
                printf("%05d %d %05d\n",node[i].Address,node[i].Data,node[i+1].Address);
            }else{
                printf("%05d %d -1\n",node[i].Address,node[i].Data);
            }
        }
    }

    return 0;
}
