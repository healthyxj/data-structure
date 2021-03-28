#include<stdio.h>

int main(){
    int begin, endding;
    
    scanf("%d%d", &begin, &endding);
    
    int sum = endding - begin;
    if(sum % 100 >= 50){    //四舍五入的表示
        sum = (endding - begin) / 100 + 1;
    }else{
        sum = (endding - begin) / 100;
    }
    
    printf("%02d:%02d:%02d\n", sum / 3600, sum % 3600 / 60, sum % 60);   //02补充位数， 时分秒可以直接表示
    
    return 0;
}
