#include<stdio.h>

/*
根据计算机组成原理，两个正数之和为负数或者两个负数之和为正数，则发生了溢出。
需要对溢出的情况进行讨论：
如果A + B > 2^63,结果为负数，但是显然A + B > C
如果A + B < -2^63，结果为正数，显然A + B < C

注意：A+B必须要放在longlong类型中与C比较。
*/

int main(){
    int i, n;
    scanf("%d", &n);
    
    long a, b, c,sum;
    for(i = 1; i <= n; i++){
        scanf("%ld%ld%ld", &a, &b, &c);
        printf("Case #%d: ", i);
        sum = a + b;
        if(a > 0 && b > 0 && sum < 0){
            printf("true\n");
        }else if(a < 0 && b < 0 && sum >= 0){
            printf("false\n");
        }else if(sum > c){  //最后只需要和大于第三个数就可以了
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    
    
    return 0;
}
