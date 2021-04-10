#include<stdio.h>

#define G 493
#define S 29

/*
相加会越界,还是需要使用数组
*/

int main(){
    int a1, b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    
    int up = 0;
    
    int ge = (c1 + c2) % 29;
    up = (c1 + c2) / 29;
    
    int shi = (b1 + b2 + up) % 17;
    up = (b1 + b2 + up) / 17;
    
    int bai = a1 + a2 + up;
    
    printf("%d.%d.%d", bai, shi, ge);
    
    return 0;
}
