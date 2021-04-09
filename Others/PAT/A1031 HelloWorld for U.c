#include<stdio.h>
#include<string.h>

/*
竖着的为n1，横着的为n2，2 * n1 + n2 - 2 = N, 并且n1 <= n2
题意要求在这样的条件下，输出U形
关键在于确定1)n1和n2的值，2)输出U形
1)可以通过不断举例子的方法，确认出n1和n2的规律， n1 = (N + 2) / 3
2)输出时采取二维数组的方法，二维数组的两维大小至少为(n + 2) / 3
*/

int main(){
    char str[100];
    gets(str);  //用gets()读入整个字符串
    
    int N = strlen(str);
    int n1 = (N + 2) / 3, n3 = n1, n2 = N - 2 * n1;
    int i = 0, j = 0;
    
    for(i; i < n1 - 1; i++){
        printf("%c", str[i]);
        
        for(j = 0; j < n2; j++){
            printf(" ");
        }
        
        printf("%c\n", str[N - 1 - i]);
    }
    
    for(i = n1 - 1; i < n1 + n2 + 1; i++){
        printf("%c", str[i]);
    }
    
    return 0;
}
