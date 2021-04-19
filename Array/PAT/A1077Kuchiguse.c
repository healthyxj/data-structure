#include<stdio.h>
#include<string.h>
/*
给出三行语句，求出公共后缀，如果没有就输出nai。
考虑到公共后缀需要从后往前枚举，因此将原字符串翻转，
*/

int i, j, n, minlen = 256, ans = 0;   //n表示读入的字符串的个数，minlen表示输入的字符串中的最小长度，ans表示相同的字符串的位数 

int main(){
    char a[100][256];
    scanf("%d", &n);    //读入的字符串的个数
    
    getchar(); //读入回车换行
    
    for(i = 0; i < n; i++){
        gets(a[i]); //读取每行的字符串，所以使用二维数组进行存储
        int len = strlen(a[i]); //因为需要求出公共后缀，就需要知道最小的长度
        if(len < minlen) minlen = len;
        
        //翻转数组
        for(j = 0; j < len / 2; j++){
            char tmp = a[i][j];
            a[i][j] = a[i][len - j - 1];
            a[i][len - j - 1] = tmp;
        }
    }
    
    //判断所有字符串
    for(i = 0; i < minlen; i++){
        char c = a[0][i];    //因为有最短的长度，所以选择第1个
        
        int same = 1;
        for(j = 1; j < n; j++){
            if(c != a[j][i]){
                same = 0;
                break;
            }
        }
        
        if(same == 1) ans++;
        else break;
    }
    
    if(ans == 0){
        printf("nai\n");
    }else{
        for(j = ans - 1; j >= 0; j--){
            printf("%c", a[0][j]);
        }
    }
    
    return 0;
} 
