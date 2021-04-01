#include<stdio.h>

/*
考虑到正负相抵，最好先相加再输出
*/

#define MaxSize 1005

int main(){
    double p[MaxSize] = {};
    int n, i;
    int exp, cnt = 0;
    double coef;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d%lf", &exp, &coef);
        p[exp] += coef;
    }
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%lf", &exp, &coef);
        p[exp] += coef;
    }
    
    for(i = 0; i < MaxSize; i++){
        if(p[i] != 0){
            cnt++;
        }
    }
    if(cnt == 0){
        printf("0");
    }else{
        printf("%d", cnt);
        for(i = 1000; i >= 0; i--){ //对于末尾没有空格的情况，可以将空格往开头放
            if(p[i] != 0){
                printf(" %d %.1lf", i, p[i]);
                //if(i != 0) printf(" ");
            }
        }
    }
    return 0;
}

