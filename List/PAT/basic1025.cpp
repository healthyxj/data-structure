#include<stdio.h>
#include<cstdio>
#include<algorithm>

using namespace std;

#define MaxSize 100001

struct NODE{
	int address,data,next;
	int flag;
}node[MaxSize];

bool cmp(NODE a,NODE b){
	if(a.flag == 0 || b.flag == 0){
		return a.flag > b.flag;
	}else{
		return a.data > b.data;
	}
} 

int main(){
	int i;
	for(i = 0;i < MaxSize;i++){
		node[i].flag = 0;
	}
	
	/*用begin,n1,n2表示起始地址,结点数,翻转的结点数*/
	int begin,n1,n2;
	scanf("%d%d%d",&begin,&n1,&n2);
	
	
	int address;
	for(i = 0;i < n1;i++){
		scanf("%d",&address);
		scanf("%d%d",&(node[address].data),&(node[address].next));
		node[address].address = address;
	}
	
	int p = begin;
	while(p != -1){
		node[p].flag = 1;
		p = node[p].next;
	}
	
	sort(node,node+n2,cmp);
	
	for(i = 0;i < n1;i++){
		if(i == n1 - 1){
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}else{
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}
	}
	
	
	
	
	return 0; 
}
