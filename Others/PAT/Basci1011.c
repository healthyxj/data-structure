#include<stdio.h>

int main(){
    int n, i = 1;
    long a, b, c;
    
    scanf("%d", &n);
    
    while(n--){
        scanf("%ld%ld%ld", &a, &b, &c);
        if(a + b > c){
            printf("Case #%d: true\n", i++);
        }else{
            printf("Case #%d: fasle\n", i++);
        }
    }
    
    
    return 0;
}
