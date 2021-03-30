#include<stdio.h>

/*
考虑使用两个数组记录一次变换前后的状态，变换后，将数组1的内容转移到数组2
而对于牌的表示，同样是使用数字表示。总共有54张牌，牌号为x
(x - 1) / 13表示牌的颜色(梅花、方块等), (x - 1) % 13 + 1表示牌的数字
*/

#define MaxSize 54

int main(){
    //表示对应的符号
    char map[5] = {'S', 'H', 'C', 'D', 'J'};
    
    int i, n;
    scanf("%d", &n);
    
    int start[MaxSize + 1], next[MaxSize + 1], end[MaxSize + 1];
    
    //初始化
    for(i = 1; i <= 54; i++){
        start[i] = i;
    }
    
    //读入
    for(i = 1; i <= 54; i++){
        scanf("%d", &next[i]);
    }
    
    int step = 0;
    for(step = 0; step < n; step++){
        for(i = 1; i <= MaxSize; i++){
            end[next[i]] = start[i];    //next是移动的顺序，因此只是作为参数
        }
        
        for(i = 1; i <= MaxSize; i++){
            start[i] = end[i];
        }
    }
    
    for(i = 1; i <= MaxSize; i++){
        if(i != 1) printf(" ");
        start[i]--;
        printf("%c%d", map[start[i] / 13], start[i] % 13 + 1);
    }
    
    return 0;
}
