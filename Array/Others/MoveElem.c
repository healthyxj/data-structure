#include<stdio.h>
#include<stdlib.h>

#define MaxSize 1000

/*
该程序用于实现将输入的数组中的0移动到末尾，其他数字顺序向前移动
输入格式
n   数组的个数
a b 0 c 0 d e f     数组中元素的值
输出结果应该为a b c d e f 0 0 
*/

void Seq1(int* num, int length){
    int i = 0, j = 0, n = length;
    int count = 0;

    for(i = 0; i < n; i++){
        if(num[i]){
            num[j++] = num[i];  //因为是0往后移动，可以考虑直接在原数组上进行覆盖，如果不是0，完全无影响
        }else{
            count++;    //用count记录0的个数
        }
    }

    for(i = n - count; i < n; i++){
        num[j++] = 0;
    }

    for(i = 0; i < n; i++){
        printf("%d", num[i]);
    }
}

void Seq2(int* num,  int length){
    int i = 0, j = 0;
    int temp;

    while(i < length){
        temp = num[i];  //先用临时的参数存储数组当前位置的值
        num[i++] = 0;   //将该位置的值赋值为0，同时位置往后移动一位
        if(temp){
            num[j++] = temp;    //如果当前的值不为0，就覆盖掉0，最终实现0全部往后移的目标
        }

    }

    for(i = 0; i < length; i++){
        printf("%d", num[i]);
    }

}

int main(){
    int n, num[MaxSize];
    int i = 0;

    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    Seq1(num, n);
    printf("\n");
    Seq2(num, n);

    return 0;
}
