**&是双向操作，用于双向传递**，特别是某些时刻返回的参数不止一个的时候。可以使用&来进行参数传递。

参数中没有&，一定是输入；有&，一定是输出

~~~c
void change(int &b){
    *b = *b + 7; 
}
//change函数获得的是地址，即输入的参数，括号里的是地址，但是函数里改变的是地址中的内容

int main(){
    int a = 5;
    printf("%d", &a);
    
    change(&a);
    
    printf("%d",&a);
}
~~~

已知前驱为prior(a),后继为next(a)，用递归的算法，求a+b

~~~c
//可以用一个坐标轴来思考，a往左走，b往右走;但是如果a很大，递归次数过多，需要对ab大小进行判断
int AddInt(int a, int b){
    if(a > b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    return Add(a,b);
}

int Add(int a, int b){
    if a == 0 return b;
    else return(Add(prior(a),next(b)));
}
~~~

顺序表

~~~c
#include<stdio.h>
#include<stdlib.h>						//Attenton:don' t forget  

#define MaxSize 100
typedef int ElementType;				
//ElementType是为了理解，可以是int，char;	Attention:typedef后要跟; 这句话可以等效为#define ElementType int

typedef struct LNode *List;				//Attention:要有* 
struct LNode{
	ElementType Data[MaxSize];			//ElementType用于存储自己需要的类型 
	int Last;							//定义列表的长度 
};

//查找元素X的位置并返回
int Find(ElementType X,List L){
	int i = 0;
	while(i <= L->Last && X != L->Data[i]){
		i++;
	}
	if(i > L->Last) return -1;					//没找到返回-1 
	else return i;								//找到返回存储位置的值 
} 

//在表PtrL第i个位置插入X 
void InsertElem(ElementType X,int i,List PtrL){
	int j = 0;
	if(PtrL->Last == MaxSize-1){
		printf("表已满\n");
		return ;								//void需要return ; 表示程序终止
	}
	if(i < 1 || i > PtrL->Last+2){				
		printf("位置不合法\n");
		return ;
	}
	for(j = PtrL->Last;j >= i-1;j--){			//Attention:i-1处也要移 
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	PtrL->Data[i-1] = X; 
	PtrL->Last++;
	return ;
}

//删除第i个位置的元素 
void DeleteElem(ElementType X,int i,List PtrL){
	int j = 0;
	if(i < 1 || i > PtrL->Last+1){
		printf("位置不合法\n");
		return ;
	}
	for(j = i;j <= PtrL->Last;j++){
		PtrL->Data[j-1] = PtrL->Data[j];
	}
	PtrL->Last--;
	return ;
}

int main(){
	
	return 0;
}
~~~





单链表

~~~c
typedef struct LNode{
    ElementType Data;
    struct LNode *Next;
}*LinkList;
~~~

单链表的创建

首先开辟头指针，然后为每个结点分配空间并复赋值，后继结点的地址要提前分配给前面的指针。

~~~c
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct LNode *List;
struct LNode{
	ElementType Data;
	List Next;						//因为是同一类型的，可以用临时定义的List 
};

//初始化，建立空的链表 
List MakeEmpty(){
	List PtrL;
	//PtrL = (LNode)malloc(sizeof(struct List));× 
	PtrL = (List)malloc(sizeof(struct LNode)); //前面是临时的，后面是总的 
	PtrL->Next = NULL;
	return PtrL;
}

//求表长
int Length(List PtrL){
	List p = PtrL;					//令p指向第一个结点 
	int i = 0;
	while(p){
		p = p->Next;
		i++;
	}
	return i;
} 

//查找第k个元素，返回地址 
List FindKth(int K,List PtrL){
	List p = PtrL;
	int i = 1;
	while(p != NULL && i < K){
		p = p->Next;
		i++;
	}
	if(i == K) return p;
	else return NULL;
}

//查找元素X的位置，返回地址 
List Find(ElementType X,List PtrL){
	List p = PtrL;
	while(p != NULL && p->Data != X){
		p = p->Next;
	}
	return p;
}

//在第i-1个结点后插入，返回链表的头指针
//Attenion:需要考虑头结点的情况 
List Insert(ElementType X,int i,List PtrL){
	List s,p;
	if(i == 1){
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = PtrL;
		return s;									//返回新表的头结点 
	}
	//p = FindKth(int i-1,List PtrL);
	p = FindKth(i-1,PtrL);							//函数只需输入参数即可 
	if(p == NULL){
		/*s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = PtrL;
		return s;*/
		printf("参数错\n");
		return NULL; 
	}
	else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;								//新表的头结点仍为PtrL 
	}
}

//删除第i个结点，仍需注意头结点的位置，关键是要找到前一个结点 
List Delete(int i,List PtrL){
	List s,p;
	if(i == 1){
		s = PtrL;
		if(PtrL != NULL) PtrL = PtrL->Next;
		else return NULL;
		free(s);
		return PtrL; 
	}
	p = FindKth(i-1,PtrL);
	if(p == NULL){
		printf("第%d个结点不存在",i-1);
		return NULL;
	}else if(p->Next == NULL){
		printf("第%d个结点不存在",i);
		return NULL;
	}else{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}

} 

int main(){
	
	system("pause");
	return 0;
}
~~~



提前说明全局变量和指针

~~~c
#include<stdio.h>
#include<stdlib.h>

#define ElementType int

typedef struct Node{
    ElementType Data;
    struct Node *Next;
}Node;

Node *p, *q, *head;

int n;

int m = sizeof(Node);
~~~

将26个字符放入到链表中

~~~c
void build(){
    int i;
    head = (Node*)malloc(m);
    
    p = head;
    
    for(i = 1; i < 26; i++){
        p->Data = i + 'a' - 1;
        p->Next = (Node*)malloc(m);
        p = p->Next;
    }
    p->Data = i + 'a' - 1;
    p->Next = NULL;
}
~~~

输出链表

~~~c
void Display(){
    p = head;
    while(p){
        printf("%d",p->Data);
        p = p->Next;
    }
}
~~~



