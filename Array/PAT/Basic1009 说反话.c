#include<stdio.h>
#include<string.h>

/*
有单词，考虑使用二维数组进行存放，每遇到一个空格就表示单词结束
*/
int main(){
    char a[85];
    gets(a);	//用a读取输入的字符
    
    char word[85][85];
    int r = 0, c = 0;	//r和c分别记录行数和列数
    int len = strlen(a); //用len记录读入字符的长度
    int i = 0;
    
    for(i = 0; i < len; i++){   
        if(a[i] != ' '){
            word[r][c++] = a[i];
        }else{
            word[r][c] = '\0';	//作为结束的标识符
            r++;
            c = 0;	//返回到下一个单词的开始
        }
    }
    
    for(i = r; i >=0; i--){ //用r来作为输出条件
        printf("%s", word[i]);	//因为是输出一整个维度，需要用string类型
        if(i > 0) printf(" ");	    //空格在最后输出的时候处理
    }
    
    
    return 0;
}
