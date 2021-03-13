#include<stdio.h>
#include<algorithm>
using namespace std;

#define MaxSize 100010
/*
对于给出地址、范围小的题目，可以尝试使用静态链表
*/

struct Node{
    int Address, Data, Next;
    int Order;  //因为是排序，所以这里用order来表示元素在原链表中的位置
}node[MaxSize];

bool cmp(Node a, Node b){
    return a.Order < b.Order;   //按order从小到大排序    
}

int main(){
    //初始化， 将所有Order置为MaxSize， 表示无效结点
    for(int i = 0; i < MaxSize; i++){
        node[i].Order = MaxSize;
    }

    int begin, N, n;
    scanf("%d%d%d",&begin, &N, &n);

    int address;
    for(int i = 0; i < N; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[address].Data, &node[address].Next);
        node[address].Address = address;
    }

    int tmp = begin, count = 0; //count用于记录有效结点的个数
    while(tmp != -1){
        node[tmp].Order = count;
        tmp = node[tmp].Next;
        count++;
    }

    sort(node, node + MaxSize, cmp);    //按Order值从小到大排序，使链表符合题意
    
    /*
    最复杂的内容。因为是每隔n个进行反转，就需要将整个链表进行分块(这里没有把参数设置好，应该根据题目中的k进行设置)。
    每一块中的处理，又需要进行细分，首先是前n-1个结点，只需要正常的倒序输出即可。对于最后一个结点，考虑是不是最后一块。
    如果不是最后一块，只需要将该结点指向下一块中的最后一个结点。如果是最后一块，又要进行细分。
    如果是最后一块，又是最后一个结点，就直接赋值为-1。如果最后一块后面仍然有结点，就需要对之后的结点进行直接输出
    */
  
    for(int i = 0; i < count / n; i++){ //对于每一块进行处理
        for(int j = (i + 1) * n - 1; j > i * n; j--){   //对于每一块中的内容需要倒序输出
            printf("%05d %d %05d\n", node[j].Address, node[j].Data, node[j - 1].Address);
        }
        printf("%05d %d ", node[i * n].Address, node[i * n].Data);
        if(i < count / n - 1){  //如果不是最后一块， 只需要输出下一块的最后一个的地址
            printf("%05d\n", node[(i + 2) * n -1].Address);
        }else{  //如果是最后一块， 需要考虑是否链表结束了
            if(count % n == 0){
                printf("-1\n");
            }else{  //链表没结束， 之后的内容要按照原来的顺序输出
                printf("%05d\n", node[(i + 1) * n].Address);
                for(int i = count / n * n; i < count; i++){
                    printf("%05d %d ", node[i].Address, node[i].Data);
                    if(i < count -1){
                        printf("%05d\n", node[i + 1].Address);
                    }else{
                        printf("-1\n");
                    }
                }
            }
        }
    }

    return 0;
}
