#include<stdio.h>
#include<string.h>
/*
主要是找到E的位置
指数为负数时，输出一定为0.  ，小数点后0的个数为exp - 1

*/

int main(){
    char str[10005];
    gets(str);
    
    int len = strlen(str);
    int i;
    
    if(str[0] == '-') printf("-");
    
    int pos = 0;    //表示E的位置
    while(str[pos] != 'E'){
        pos++;
    }
    
    int exp = 0;    //存放指数
    for(i = pos + 2; i < len; i++){ //从符号位后面开始
        exp = exp * 10 + str[i] - '0';
    }
    
    if(exp == 0){   //如果指数位为0
        for(i = 1; i < pos; i++){
            printf("%c", str[i]);
        }
    }
    
    if(str[pos + 1] == '-'){    //如果指数位为负
        printf("0.");
        
        for(i = 0; i < exp - 1; i++){   //输出0的个数
            printf("0");
        }
        
        printf("%c", str[1]);   //输出第一位
        
        for(i = 3; i < pos; i++){
            printf("%c", str[i]);
        }
    }else{
        for(i = 1; i < pos; i++){
            if(str[i] == '.'){
                continue;
            }
            
            printf("%c", str[i]);
            
            if(i == exp + 2 && pos - 3 != exp){
                //原小数点和E之间的位数不能小于exp
                printf(".");
            }
        }
        
        for(i = 0; i < exp - (pos - 3); i++){
            printf("0");
        }
    }
    
    return 0;
}
