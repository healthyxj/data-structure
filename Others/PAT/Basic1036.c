#include<stdio.h>

//用于输出完整的行
void print1(char c, int n){
    int j = 0;
    
    while(j < n){
        printf("%c", c);
        j++;
    }
    
    printf("\n");
}

void print2(char c, int n){
    //int t = n / 2;
    int j = 0;
    
    printf("%c", c);
    
    while(j < n - 2){
        printf(" ");
        j++;
    }
    printf("%c\n", c);
}

int main(){
    int n;
    char c;
    
    scanf("%d %c", &n, &c);
    
    int rown;
    
    //因为是四舍五入，需要分开处理
    if(n % 2 == 0){
        rown = n / 2;
    }else{
        rown = n / 2 + 1;
    }
    
    int i = 0, j = 0;
    int cnt = 0;
    
    for(i = 0; i < rown; i++){
        if(cnt == 0){
			print1(c, n);
        }else if(cnt == rown - 1){
			print1(c, n);
        }else{
        	print2(c, n);   
        }
        cnt++;
    }
    return 0;
}
