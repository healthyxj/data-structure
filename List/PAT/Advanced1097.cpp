#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MaxSize 100005

struct Node{
    int Address, Data, Next;
    int Order;
}node[MaxSize];

//将isExist默认赋值为false
bool isExist[MaxSize] = {false};
bool cmp(Node a, Node b){
    return a.Order < b.Order;
}


int main(){
    memset(isExist, false, sizeof(isExist));
    for(int i = 0; i < MaxSize; i++){
        node[i].Order = 2 * MaxSize;    //目的是分两种情况，一种是有效的结点，另一种是要移除的结点
    }

    int begin, N, address;
    scanf("%d%d", &begin, &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[address].Data, &node[address].Next);
        node[address].Address = address;
    }

    int LiValid = 0, LiRemoved = 0, tmp = begin;
    while(tmp != -1){
        //如果isExist中没有，就设置为true，同时有效结点数增加
        if(!isExist[abs(node[tmp].Data)]){
            isExist[abs(node[tmp].Data)] = true;
            node[tmp].Order = LiValid++;
        }else{
            //无效结点数因为要在有效结点输出完后输出，所以需要order加一个MaxSize
            node[tmp].Order = MaxSize + LiRemoved++;
        }
        tmp = node[tmp].Next;
    }

    int count = LiValid + LiRemoved;    //count作为总共要输出的结点数
    if(count == 0){
        printf("0 0 -1\n");
    }else{
        sort(node, node + MaxSize, cmp);
        for(int i = 0; i < count; i++){
            if(i != count -1 && i != LiValid - 1){  //在有效结点数和总数目到达之前需要进行分别处理
                printf("%05d %d %05d\n", node[i].Address, node[i].Data, node[i + 1].Address);
            }else{
                printf("%05d %d -1\n", node[i].Address,node[i].Data);
            }
        }
    }

    return 0;
}
