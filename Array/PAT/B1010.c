#include<stdio.h>

/*
B1010
因为没有给出范围，所以要使用while循环来读取。
*/

#define MaxSize 1005

int main(){
    int c, e;
    int a[MaxSize] = {0};
    
    while(scanf("%d%d", &c, &e) != EOF){
        a[e] = c;
    }
    
    int  i, count = 0;  //定义count统计多项式的个数
    for(i = 1; i < MaxSize; i++){
        a[i - 1] = i * a[i];
        a[i] = 0;   //这一句不能少，因为最后一个求导数之后是为空的
        if(a[i - 1] != 0) count++;
    }
    
    if(count == 0){
        printf("0 0\n");
    }else{
        for(i = 1000; i >= 0; i--){	//这里i不能从MaxSize开始，必须从最大1000开始
            //a[i] == 0时什么也不做
            if(a[i] != 0){
                printf("%d %d", a[i], i);
                count--;
                if(count != 0) printf(" ");
                //printf("0 0");
            }
            
        }
    }
    
    
    return 0;
}
