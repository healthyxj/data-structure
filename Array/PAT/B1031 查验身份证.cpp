#include<cstdio>
#include<cstring>

/*
如果存在非整数，就输出该身份证号。
可以使用数组存放权重和校验和，用flag存放是否全部合格。但是c语言没有布尔类型，
*/

int weight[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char change[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    
int main(){
    char str[20];
    
    int n;
    int i, j, last = 0;
    bool flag = true;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%s", str);
        
        last = 0;   //注意：临时定义的变量最好需要在每个循环重新赋值!!!!
        for(j = 0; j < 17; j++){
            if(!(str[j] >= '0' && str[j] <= '9')){
                break;
            }
            last += (str[j] - '0') * weight[j]; //字符转换成常量
        }
        
        if(j < 17){
            flag = false;
            printf("%s\n", str);
        }else{
            if(change[last % 11] != str[17]){
                flag = false;
                printf("%s\n", str);
            }
        }
        
    }
    
    if(flag == true) printf("All passed\n");
    
    return 0;
}
