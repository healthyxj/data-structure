#include<stdio.h>

/*
因为是一个环，一旦一边的总路程算出，根据环的"周长"就可以算出另一边的路程。最后求出最小值即可
正因为是环，出现left>right的情况，可以将两个数互换。
可以用dis[i]表示1号结点到达i号结点下一个结点的距离。
两个点之间的距离就可以表示为dis[right - 1] - dis[left - 1]。
*/

#define MaxSize 100010

int main(){
    int dis[MaxSize], A[MaxSize];
    int n, i, sum = 0, tmp = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        scanf("%d", &A[i]);
        sum += A[i];
        dis[i] = sum;
    }

    int time, left, right;
    scanf("%d", &time);

    for(i = 0; i < time; i++){
        scanf("%d%d", &left, &right);
        if(left > right){   //注意如果left和right的大小
            tmp = right;
            right = left;
            left = tmp;
        }
        if(sum - (dis[right - 1] - dis[left - 1]) > dis[right - 1] - dis[left - 1]){
            tmp = dis[right - 1] - dis[left - 1];
        }else{
            tmp = sum - dis[right - 1] + dis[left - 1];
        }
        printf("%d\n", tmp);
    }

    return 0;
}
