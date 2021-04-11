#include<stdio.h>
#include<string.h>

/*
因为不超过1000位，必然使用字符数组进行存放。
关键在于将字符转化为数字，因为ASCII码是连续表示的，因此可以使用相减来得到
*/

int main(){
    char str[1005];
    gets(str);
    int count[10] = {0};
    
    int i;
    for(i = 0; i < strlen(str); i++){
        count[str[i] - '0']++;
    }
    
    for(i = 0; i < 10; i++){
        if(count[i] != 0) printf("%d:%d\n", i, count[i]);
    }
    
    return 0;
}
