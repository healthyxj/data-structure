#include<cstdio>

/*
难点在于对输入具体日期的转换，以及与最大和最小年月日的比较。
具体思路是利用结构存储年纪最小和最大的姓名和年龄。
注意：
1)由于日期的左右边界都是固定的，可以考虑使用结构进行存放
2)由于并不需要具体的年月日，只是逻辑上的比较，可以使用bool(相应就要使用c++)来表征年轻和年长;而与最年长、最年轻、边界值比较，可以使用函数
3)设置最年轻和最年长的边界值
*/

struct birth{
    char name[10];
    int Year;
    int Month;
    int Day;
}young, old, left, right, tmp;

void init(){
    //设置最左边和最右边的边界值
    left.Year = 1814;
    left.Month = 9;
    left.Day = 6;
    right.Year = 2014;
    right.Month = 9;
    right.Day = 6;
    
    //设置最年轻的边界值
    young.Year = 1814;
    young.Month = 9;
    young.Day = 6;
    
    //设置最年长的边界值
    old.Year = 2014;
    old.Month = 9;
    old.Day = 6;
}

//用于判断a是否比b年轻，如果a比b年轻就返回true
bool isYounger(birth a, birth b){
    if(a.Year != b.Year){
        return a.Year >= b.Year;
    }else{
        if(a.Month != b.Month){
            return a.Month >= b.Month;
        }else{
            return a.Day >= b.Day;
        }
    }
}

//判断a是否比b年长，如果a比b年纪大就返回true
bool isOlder(birth a, birth b){
    if(a.Year != b.Year){
        return a.Year <= b.Year;
    }else{
        if(a.Month != b.Month){
            return a.Month <= b.Month;
        }else{
            return a.Day <= b.Day;
        }
    }
}

int main(){
    int i, n, num = 0;
    scanf("%d", &n);
    
    init();
    
    for(i = 0; i < n; i++){
        scanf("%s %d/%d/%d", tmp.name, &tmp.Year, &tmp.Month, &tmp.Day);
        if(isYounger(right, tmp) == true && isOlder(left, tmp) == true){
            num++;
            if(isYounger(tmp, young)){
                young = tmp;
            }
            if(isOlder(tmp, old)){
                old = tmp;
            }
        }
    }
    
    if(num == 0){
        printf("0\n", num);
    }else{
        printf("%d", num);
        printf(" %s %s\n", old.name, young.name);
    }
    
    
    return 0;
}
