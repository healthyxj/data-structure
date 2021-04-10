#include<stdio.h>

#define Gal 493 //定义的时候要整数就整数，不要用29 * 17来代替，血的教训
#define Sic 29

int main(){
    int a1, a2, a3;
    int b1, b2, b3;
    
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    
    int price = a1 * Gal + a2 * Sic + a3;
    int money = b1 * Gal + b2 * Sic + b3;
    
    int change = money - price;
    if(change < 0){
        change = -change;
        printf("-");
    }
    //printf("%d\n", change);
    
    printf("%d.%d.%d\n", change / Gal , change % Gal / Sic, change % Sic);
    
    return 0;
}
