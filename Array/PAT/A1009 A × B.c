#include<stdio.h>

struct poly{
    int exp;
    double coef;
}Poly[1001];

int main(){
    double res[2001] = {};  //需要赋初始值，并且因为是乘法，需要将参数设置为2000
    double coef;
    int m, n, i, j, exp,cnt = 0;

    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d%lf", &Poly[i].exp, &Poly[i].coef);
    }

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%lf", &exp, &coef);
        for(j = 0; j < m; j++){
            res[exp + Poly[j].exp] += coef * Poly[j].coef; 
        }
    }

    for(i = 0; i < 2001; i++){
        if(res[i] != 0) cnt++;    
    }

    printf("%d",cnt);
    for(i = 2000; i >= 0; i--){
        if(res[i] != 0) printf(" %d %.1lf", i, res[i]);
    }


    return 0;
}
