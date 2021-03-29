#include<stdio.h>

/*
数组Basic1008
虽然题目给出了具体的限制，但是可以不用管过程，只需要输出结果即可。
*/

int main(){
    int n, m, i, cnt = 0;
    int a[105];
    
    scanf("%d%d", &n, &m);
    
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    m = m % n;	//因为题目未说m的上限需要考虑移过头的情况
    
    for(i = n - m; i < n; i++){
        printf("%d ", a[i]);
    }
    
    for(i = 0; i < n - m; i++){
        printf("%d", a[i]);
        if(cnt++ < n - m -1) printf(" ");
    }
    
	return 0;   
}
