#include<stdio.h>

/*
因为题目的范围是2的30次方-1，对于二进制肯定是会超出范围的。
考虑用数组存放转换后的每一位
*/
int main(){
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    
    int c[40];
    
    int sum = a + b;
    int tmp = 0;
    
    if(sum == 0){
        printf("0\n");
    }else{
	    while(sum != 0){
        	c[tmp] = sum % d;
        	sum = sum / d;
        	tmp++;
    	}     
        
        //int i = 0;
        while(tmp > 0){
            printf("%d",c[tmp - 1]);
            tmp--;
        }
        printf("\n");
    }
    
    return 0;
}
