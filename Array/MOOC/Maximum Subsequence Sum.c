#include<stdio.h>

#define MaxSize 10001

/*
该程序用于寻找一串序列中的最大子列，返回最大值，子序列开始的数值和结束的数值
示例
10
-10 1 2 3 4 -5 -23 3 7 -21
输出结果应为10 1 4
*/

int main(){
	int n;
	int a[MaxSize];
	int i;
	
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	
	int ThisSum = 0,MaxSum = -1;  
	int MaxFirst,MaxLast;
	int num = 0;
	
	for(i = 0;i < n;i++){
		ThisSum += a[i];
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;
			MaxFirst = num; //将最大子序列开始的那个数进行赋值
			MaxLast = i;	
		}
		if(ThisSum < 0){
			ThisSum = 0;
			num = i + 1;	//用于保存最大子序列的开始的那个数
		}
	}
	if(MaxSum < 0){
		printf("%d %d %d",0,a[0],a[n-1]); //根据题意，如果最大值小于0，就输出0和序列开始和结束的值
	}else {
		printf("%d %d %d",MaxSum,a[MaxFirst],a[MaxLast]);
	}
	
	return 0;
}
