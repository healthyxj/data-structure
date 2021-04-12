#include<stdio.h>
#include<string.h>

//用二维字符数组存放字符串
char map[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main(){
    char str[110];
    gets(str);  //只有纯c才能使用gets，c++不能使用gets
    
    int i, sum = 0;
    for(i = 0; i < strlen(str); i++){
        sum += str[i] - '0';
    }
    
//     int ans[3] = {0};
//     int bai = sum / 100;
//     int shi = sum % 100 / 10;
//     int ge = sum % 10;
    
    int num = 0;    //用于统计有效位数
    int ans[15];
    while(sum != 0){
        ans[num] = sum % 10;
        num++;
        sum /= 10;
    }
    
    for(i = num - 1; i >= 0; i--){
        printf("%s", map[ans[i]]);
        if(i > 0) printf(" ");
    }
    
    return 0;
}
