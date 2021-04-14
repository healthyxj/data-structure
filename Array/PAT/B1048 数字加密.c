#include<stdio.h>
#include<string.h>
#define MaxSize 110

/*
可以对字符串进行翻转
*/

void reverse(char s[]){
    int len = strlen(s);
    int i;
    
    for(i = 0; i < len / 2; i++){
        int tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - i - 1] = tmp;
    }
}

int main(){
    char a[MaxSize], b[MaxSize], ans[MaxSize] = {0};
    scanf("%s %s", a, b);   //因为在同一行，所以只能用scanf
    
    reverse(a);
    reverse(b);
    
    int len1 = strlen(a);
    int len2 = strlen(b);
    int len = len1 > len2 ? len1 : len2;
    int i;
    
    for(i = 0; i < len; i++){
        int numA = i < len1 ? a[i] - '0' : 0;   //需要进行比较时，最好将char转换成int类型
        int numB = i < len2 ? b[i] - '0' : 0;
        
        if(i % 2 == 0){
            int tmp = (numA + numB) % 13;
            if(tmp == 10) ans[i] = 'J';
            else if(tmp == 11) ans[i] = 'Q';
            else if(tmp == 12) ans[i] = 'K';
            else ans[i] = tmp + '0'; 
        }else{
            int tmp = numB - numA;
            if(tmp >= 0) ans[i] = tmp + '0';
            else ans[i] = tmp + 10 + '0';
        }
    }
    
    reverse(ans);
    puts(ans);  //用puts输出
    
    return 0;
}
