#include<stdio.h>

/*
因为这里没有要求输入学生的个数具体为多少，
并且只要求输出成绩最高和最低的学生信息，
所以只需要创建包含学生信息的结构，用于记录最高和最低学生的相关信息，每次读入就进行比较。
注意
1)读入的字符串要使用char[]字符数组进行存储
2)读入字符串不能加&
3)最高分数要设置为-1
*/

struct Stu{
    char Name[15];
    char ID[15];
    int score;
}tmp, max, min;

int main(){
    int n, i;
    scanf("%d", &n);

    max.score = -1;
    min.score = 101;

    for(i = 0; i < n; i++){
        scanf("%s%s%d", tmp.Name, tmp.ID, &tmp.score);

        if(tmp.score > max.score){
            max = tmp;
        }

        if(tmp.score < min.score){
            min = tmp;
        }
    }

    printf("%s %s\n", max.Name, max.ID);
    printf("%s %s\n", min.Name, min.ID);

    return 0;
}
