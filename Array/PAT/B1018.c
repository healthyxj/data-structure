#include<stdio.h>

using namespace std;
/*
全部使用if语句会报错
字符最好能转换为数字，方便比较和记录
考虑到布能够赢锤子，锤子能赢剪刀，剪刀能赢布。将0、1、2对应为B、C、J。
因此k1赢的条件为(k1 + 1) % 3 == k2，平手的条件为k1 == k2
*/

int change(char c){
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
}

int main(){
    char map[3] = {'B', 'C', 'J'};

    int n;
    scanf("%d" , &n);

    int A[3] = {0}, B[3] = {0}; //0、1、2分别表示赢输平的次数
    int gesA[3] = {0}, gesB[3] = {0};   //记录甲乙三种手势的次数

    int i, k1, k2;
    char c1, c2;

    for(i = 0; i < n; i++){
        getchar();  //吸收空格
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);

        if(k1 == k2){
            A[1]++;
            B[1]++;
        }else if((k1 + 1) % 3 == k2){
            A[0]++;
            B[2]++;
            gesA[k1]++;
        }else{
            B[0]++;
            A[2]++;
            gesB[k2]++;
        }
    }

    printf("%d %d %d\n", A[0], A[1], A[2]);
    printf("%d %d %d\n", B[0], B[1], B[2]);

    int max1 = 0, max2 = 0;

    for(i = 1; i < 3; i++){
        if(gesA[i] > gesA[max1]) max1 = i;
        if(gesB[i] > gesB[max2]) max2 = i;
    }

    printf("%c %c\n", map[max1], map[max2]);

    return 0;
}
