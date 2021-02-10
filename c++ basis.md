# 一、头文件、输入输出、格式、基本运算

输出hello， world!

头文件是#include<iostream>。因为在VScode中运行，按住ctrl+alt+n

~~~c++
#include<iostream>
//i 代表 input; o 代表 output; stream 代表 流

using namespace std;
//使用命名空间， c++里有默认的std, standard 代表标准

//程序从主函数开始执行， 即main函数
int main(){
    cout<<"Hello world!"<<endl;
    //endl 表示输出换行

    return 0;
}
~~~

C语言中头文件是以.h为后缀的，c++头文件不加后缀。C语言中string.h作为头文件，c++中用cstring；C语言的math.h，c++中为cmath

## 1、输入输出

c++在进行输入时需要从流中提取数据，在输出时需要向流中插入数据，提取和插入是通过在流类库中重载"<<"">>"运算符来实现的。

### a、预定义的标准流对象

* cin
  * 是istream类的对象，用于处理标准输入（即键盘输入）
  * 带缓冲区，与>>搭配使用
* cout
  * 是ostream类的对象，用于处理标准输出（即屏幕输出）
  * 待缓冲区，与<<搭配使用
* cerr和clog
  * 是ostream类的对象，用于处理标准出错信息，将出错信息显示到屏幕上
  * 与 <<搭配使用
####  cin的使用

~~~c++
int a;
cin>>a;
~~~

若从键盘上输入10，10只是<b>存入缓冲区</b>，不能被>>运算符提取。当<b>按下回车键，相当于执行endl语句</b>，缓冲区的内容才<b>被刷新形成输入流</b>，被<b>>>运算符提取传递给cin对象</b>，由cin对象送到变量a中进行存储。

如果输入的是"abc"，则提取操作会失败，cin流被置为出错状态。只有正常状态下才能从输入流中提取数据，这是c++I/O安全性的体现。

cin对象<b>可以一次读入多个变量的值</b>，因为>>返回的是istream的引用，可以连续提取数据。

~~~c++
char c1,c2;
cin>>c1>>c2;
~~~

若把'a'、'b'字符输入，则'a'、'b'字符分别送到c1和c2中。输入多个数值时，要在数值之间<b>加空格以区分</b>。也可以<b>每输入一个数据后按回车键</b>，也可以正常读入数据。

~~~c++
#include<iostream>

using namespace std;

int main(){

    char c1,c2;
    cin>>c1>>c2;
    cout<<c1<<"   "<<c2;

    return 0;
}
~~~

cin对象可以对不同类型的变量读入数据。当键盘中正确输入值时，cin会将值分别存储到对应的变量中。字符变量的读入可以采用字符数组进行存储，但是需要确保输入的字符串不超出字符数组的大小。

~~~c++
#include<iostream>

using namespace std;

int main(){

    char c1;
    char d[10];
    float f1;
    string s; 
    cin>>c1>>f1>>s>>d;
    cout<<c1<<"   "<<d<<"  "<<f1<<s;

    return 0;
}
~~~
#### cout的使用

可以用cout输出变量。

cout可以输出指针和引用类型的数据。<b>地址符号&在等号右边表示取地址，&在左边表示引用,即两个变量指向同一个地址。</b>

cout可以连续输出数据。

~~~c++
#include<iostream>

using namespace std;

int main(){

    int a = 10,*p;
    int &b = a;         //把a的值存储到b的地址中。× 将b的指针指向a
    p = &a;             //把a的地址赋给p， 即p是a的地址
    string s = "c++";   //让字符串s的值为c++
    string* ps = &s;    //将s字符串的地址赋值给ps
    
    cout<<p<<endl;      //输出a的地址
    cout<<b<<endl;      //输出b的值，因为与a指向同一地址， b的值为a的值
    cout<<*p<<endl;     //输出指针的内容， 即a的值
    cout<<ps<<endl;     //输出ps的地址
    cout<<*ps<<endl;    //ps加了*表示取内容， 即输出s的值，即c++

    return 0;
}
~~~

## 2、精度、域宽、填充字符的设置

要引入iomanip，#include<iomanip>

|       操作符        |             功能              |
| :-----------------: | :---------------------------: |
|   setfill(char c)   |     设置以c表示的填充字符     |
| setprecision(int n) |     设置以n表示的数值精度     |
|     setw(int n)     | 设置以n表示的域宽(默认右对齐) |

~~~c++
#include<iostream>
#include<iomanip>
//用于设置精度、域宽等
#include<cmath>

using namespace std;

int main(){

    double b = sqrt(2.0);
    for(int i = 0;i < 5;i++){
        cout<<fixed;       //加了这句话能够按照小数点后作精度，否则会连小数点前
        cout<<setprecision(i)<<b<<endl;
    }
    cout<<"当前的精度为"<<cout.precision()<<endl;
    cout<<"当前的域宽为"<<cout.width()<<endl;
    //cout<<left;   加了这句话会变成左对齐
    cout<<setw(9)<<b<<b<<endl;  //域宽的设置要大于字符长度才能够有效果
    cout<<"当前填充字符为"<<endl;

    //只要在输出字符前，改变同一语句里的顺序对结果没有影响
    cout<<setfill('*')<<setw(10)<<b<<endl;  //****1.4142
    cout<<setw(10)<<setfill('*')<<b<<endl;  //****1.4142

    return 0;
}
~~~
|   操作符   |             功能              |
| :--------: | :---------------------------: |
|    oct     |      八进制格式输出数据       |
|    dec     |      十进制格式输出数据       |
|    hex     |     十六进制格式输出数据      |
|    endl    |  插入换行符并刷新输出缓冲流   |
| uppercase  |    十六进制输出时字母大写     |
|   skipws   |        输出时跳过空白         |
|   flush    |            刷新流             |
|    left    |            左对齐             |
|   right    |            右对齐             |
| scientific |        科学计数法输出         |
|   fixed    |        定点数方式输出         |
|  showbase  | 输出前缀(八进制0，十六进制0x) |
| showpoint  |     输出浮点数时带小数点      |
|  showpos   |        输出正整数时加+        |

## 3、基本运算

 加、减、乘、除、取余。

~~~c++
//用于计算某个位数大于等于3的整数的个位数、十位数和百位数
#include<iostream>
#include<iomanip>
//用于设置精度、域宽等
#include<cmath>

using namespace std;

int main(){

    int a;
    cout<<"请输入一个整数"<<endl;
    cin>>a;
    
    int ge, shi, bai;
    ge = a % 10;
    shi = a / 10 % 10;
    bai = a / 100 % 10;
    cout<<ge<<setw(2)<<shi<<setw(2)<<bai<<endl;

    return 0;
}
~~~

自增自减，加等于，减等于

# 二、分支结构

## 1、运算符

算术运算符

逻辑运算符

与&&	或||	非！ 

&&和||前面满足条件，后面就不会再检测了

~~~~c++
#include<iostream>
using namespace std;
int main(){
    float score;
    cin>>score;
    //符合正态分布
    if(score >= 70){
        if(score < 80){
            cout<<"成绩中等"<<endl;
        }else if(score <90){
            cout<<"成绩良好"<<endl;
        }else{
            cout<<"成绩优秀"<<endl;
        }
    }else{
        if(score >= 60){
            cout<<"成绩合格"<<endl;
        }else{
            cout<<"成绩不合格"<<endl;
        }
    }

    return 0;
}
~~~~

优先级

&& 优先级高于 ||，！优先级高于所有关系运算和算术运算




# 三、循环结构

## a、for、break、continue

for语句

for(i = 1; i <= n; i++){

​	循环体

}

break能够<b>直接跳出所在的循环</b>。

~~~c++
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i = n;i >= 1; i--){
        if(i == 5) break;
        cout<<i<<endl;
    }
    
    return 0;
}
~~~



~~~c++
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long pre1 = 1,pre2 = 1;
    long long k = 0;

    if(n == 1 || n ==2){
        cout<<1<<endl;
    }else{
        for(int i = 3;i <= n;i++){
            k = pre1 + pre2;
            pre2 = pre1;
            pre1 = k;
        }
    }
    cout<<k<<endl;

    return 0;
}
~~~

continue跳出当前循环

~~~c++
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 0;
    while(i <= n){
        i++;
        if(i % 3 == 0){
            continue;
        }					//注意：循环更新和continue的顺序
        cout<<i<<endl;
    }
    return 0; 
}
~~~



## b、while、do while语句

初始条件

while(循环条件){

循环体；循环更新；

}

do while{}; 至少执行一次

### for、while的区别

* for省略测试条件时，默认条件为true
* for语句可以用初始化语句声明一个局部变量，while不可以
* 循环体中包含continue，for语句跳到循环更新处，while直接跳到循环条件处
* 无法预知循环次数时，用while语句

# 四、函数

函数是对实现某一功能的代码的模块化封装。

函数包括：函数原型、定义和调用

## 函数定义

返回值类型 函数名（参数类型 参数名1，参数类型 参数名2，……）{

执行语句;

返回值;

}

如果没有返回值，则返回类型为void

~~~c++
//求两个数相加
#include<iostream>
using namespace std;

int add(int a, int b);	//函数原型的声明，参数名称可以不写，但是要表明参数的类型

int main(){
    int n;
    cin>>n;
    int *C = new int[n];	//创建动态数组,int *C = new 类型[数组数目]
    int a,b;

    for(int i = 0;i < n;i++){
        cin>>a>>b;
        C[i] = add(a,b);	//函数调用
    }
    for(int i = 0;i < n;i++){
        cout<<C[i]<<endl;
    }

    return 0;
}

int add(int a,int b){	//函数的定义
    return a+b; 
}
~~~

## 实例

传值调用，使用指针

1、交换两个给定的整数

~~~c++
//输入两个整数a，b，交换后输出
#include<iostream>
#include<iomanip>
using namespace std;

void swap1(int a, int b);
void swap2(int &a, int &b);

int main(){
	int a,b;
    cin>>a>>b;
    
    swap1(a,b);
    cout<<a<<setw(2)<<b<<endl;
    swap2(a,b);
    cout<<a<<setw(2)<<b<<endl;
    
    return 0;
}

void swap1(int a, int b){	//传值参数,对函数外的结果没有改变
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap2(int &a, int &b){	//引用参数,对函数外的结果有改变
    int temp;
    temp = a;
    a = b;
    b = temp;
}
~~~

2、输入n个数存入到数组中，并求出这些数的和

~~~c++
#include<iostream>
using namespace std;

int a[1000];

long long sum(int a[], int n);	//数组作为参数时，括号里不能有数字

int main(){
    int n;
    cin>>n;
    
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    cout<<sum(a,n)<<endl;	//只要将数组的符号作为参数即可 sum(a[],n)×
    
    return 0;
}

long long sum(int a[], int n){
    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum += a[i];
    }
    return sum;
}
~~~

3、输入n个字符，如果是小写的就转化为大写字母，并输出转化后的字符串

~~~c++
#include<iostream>
#include<cstring>
using namespace std;

void convert1(string s){
    for(int i = 0;i < s.length();i++){	//要读取字符串数组的长度，需要用cstring头文件
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }
}

void convert2(string &s){	//使用了引用参数
    for(int i = 0;i < s.length();i++){	//注意是s.length()，括号少不了
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }
}

int main(){
    string s;
    cin>>s;
    convert1(s);
    cout<<s<<endl;
    convert2(s);
    cout<<s<<endl;
    
    return 0;
}
~~~

4、函数调用，求最大公约数和最小公倍数

辗转相除法

~~~c++
#include<iostream>
using namespace std;

int gcd(int x, int y){	//最大公约数
    int t;
    t = x % y;
    while(t != 0){
        x = y;	
        y = t;
        t = x % y;;
    }
    return y;
}

int lcm(int x, int y){	//最小公倍数
    return x * y / gcd(x,y);
}

int main(){
    int a,b;
    cin>>a>>b;
    
    cout<<"最大公约数:"<<gcd(a,b)<<" "<<"最小公倍数:"<<lcm(a,b)<<endl;
    
    return 0;
}
~~~

## 函数重载（多态）

函数重载指多个重名函数（参数数目、类型、顺序不同）。

### 实例

1、建立一个函数，对于字符串类型数据取其长度的一半，对于浮点数类型，求其值的二分之一。

~~~c++
#include<iostream>
#include<cstring>
using namespace std;

float half(float f){
    return f / 2;
}

string half(string s){
    int n = s.length() / 2;
    char *str = new char[n];
    for(int i = 0;i < n;i++){
        str[i] = s[i];
    }
    return str; 
}

int main(){
    float n;
    string st;
    cin>>n>>st;
    
    cout<<half(n)<<half(st)<<endl;
    
    return 0;
}
~~~

# 五、递归

结束条件

## 实例

1、输入n个整数，倒序输出所有整数。

~~~c++
#include<iostream>
using namespace std;

int a[1000];

void print(int n){
    cout<<a[n]<<endl;
    if(n > 0){
        print(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    print(n-1);
    
    return 0;
}
~~~
# 六、数组

有相同数据类型的变量集合为数组。

## 定义 

**一维数组**的静态定义：

**类型说明符 数组名[常量表达式];**

常量表达式必须为整形常量，不能是变量，数值必须为已知的数值。

注意事项

* 在定义时可以对数组初始化。int a[3] = {1,2,3};
* 定义初始化时可以不指定长度 int a[] = {1,2,3,5,6};
* 非定义时不可以整体赋值 a[3] = {1,2,3};×
* 不可以对数组变量之间进行赋值
* 系统不会检查下标是否有效，超出下标的值也不会报错

### 一维数组的应用

int a[1000000];如果放在main函数里需要分配较大的空间，会报错。需要放在main函数外，作为全局的静态数组。

~~~c++
#include<iostream>
using namespace std;
int main(){
    int b[5] = {1,2,3};
    int c[] = {1,2,3,8,45,6,46,874};
    
    cout<<sizeof(int)<<endl;
    cout<<sizeof(c)<<"  "<<sizeof(b)<<endl;	//32 20。一个分配给4个字节
    
    for(int i = 0;i < 15;i++){
        b[i] = i;
    }
    for(int i = 0;i < 15;i++){
        cout<<b[i]<<endl;
    }
    
    return 0;
}
~~~

1、逆序输出

ctrl+z回车 停止并运行。

~~~c++
#include<iostream>
using namespace std;
#define maxn 105
int a[maxn];
int main(){
    int i = 0, x;
    
    while(cin>>x){
        a[i++] = x;
    }
    
    for(int j = i - 1;j >= 0;j--){
        cout<<a[j]<<endl;
    }
    
    return 0;
}
~~~

2、数组做函数的参数

#include<cstring>

bool a[1005];

memset(a,0,sizeof(a));将a数组里的所有内容置0

输入n个学生的成绩（整数），存入数组a[]中，求总成绩和平均成绩（浮点数）

~~~c++
#include<iostream>
using namespace std;

int a[105];

int add(int a[],int n){	//其实就是a[n]
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    int n,s;
    float avg;
    
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    s = add(a,n);	//注意，传递参数的时候只需要数组名即可，add(a[],n) ×
    avg = float(s) / n;
    
    cout<<s<<" "<<avg<<endl;
    
    return 0;
}
~~~

一维数组的动态定义

类型说明符 *数组名 = new 类型名[常量或变量表达式];

使用<b>new分配的数组，使用完毕需要用delete释放空间。</b>

delete []数组名



### 动态数组的应用

 统计不及格的人数

~~~c++
#include<iostream>
using namespace std;

int count(int a[],int n){
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(a[i] < 60)
            sum++;
    }
    return sum;
}

int main(){
    int n,s;
    cin>>n;
    
    int *a = new int[n];
    
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    s = count(a,n);
    cout<<s<<endl;
    
    delete []a;	//释放空间
    
    return 0; 
}
~~~

## 二维数组

类似一维数组

二维数组做参数时，第一维可以省略，第二位不能省略。

# 七、字符串与字符串

字符串：存储在内存的连续字节中的一系列字符。

## c风格字符串定义

最后一个是\0表示字符串，否则是字符数组

数组或字符串长度

sizeof()、strlen()

sizeof()返回所占总空间的字节数。-针对整型字符型数组或字符型指针

strlen()返回字符数组或字符串所占的字节数

sizeof不能返回动态分配的内存空间的大小

 ~~~c++
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s1[100];
    char s2[20] = "hello";
    char s3[3] = {'a','b','c'};
    char s4 = 'n';
    
    cin>>s1;	//cin 遇见空格会停止
    cout<<strlen(s1)<<endl;
    cout<<s1<<endl;
    
    s1[5] = '\0';
    cout<<s1<<endl;
    
    return 0;
}
 ~~~

cin使用空格、制表符、换行符来确定字符串的结束位置，因此字符串只能接受一个大那次，换行符保留在输入序列中。

getline（）:读取一行，知道遇到换行符，丢弃换行符

get()读取一行，直到遇到换行符，保留换行符.再调用一次

~~~c++
#include<iostream>
#include<cstring>//c-风格字符串 头文件 
#include<string>//string对象字符串 头文件 
using namespace std;
const int maxsize=100;
int main()
{
	char s1[maxsize],s2[maxsize],s3[maxsize],s4[maxsize];
	string str1,str2;
//	cin.getline(s1,maxsize);
//	cout<<strlen(s1)<<endl;
//	cout<<s1<<endl;
//	cin.getline(s2,maxsize);
//	cout<<strlen(s2)<<endl;
//  cout<<s2<<endl;
//    cin.get(s3,maxsize).get();
//    cout<<s3<<endl;
//    cin.get(s4,maxsize);
//    cout<<s4<<endl;
//    cin>>s3;
//    cout<<s3<<endl;
//    cin.get();
//    cin.getline(s4,maxsize);
//    cout<<s4<<endl;
 	//cin>>str1;//只读一个单词 
    //cout<<str1<<endl;
    //cin>>str2;//只读一个单词 
    //cin.get();
	getline(cin,str2);//会读换行符 
    cout<<str2<<endl;
    getline(cin,str1);//会读换行符 
    cout<<str1<<endl;
    return 0;
}
~~~

## 应用



~~~c++
#include<iostream>
#include<string>
using namespace std;

int count1(string s)
{
	int len,i=0,num=0;
	len=s.length();
	while(i<len)
	{
		while(s[i]==' ')//跳过多个空格 
			i++;
		if(i<len)
			num++;
		while(s[i]!=' '&&i<len)//跳过一个单词 
			i++;
	}
	return num; 
 } 
 
int count2(string s)
{
	int len,i=0,num=0;
	len=s.length();
	char c=' ';
	while(i<len)
	{
		i=s.find(c,i);
		//cout<<i<<endl;
		if(i>=0&&i<len)
		{
			if(s[i+1]!=c)
				num++;
			i++;
		}
		else
			break;		
	}
	return num; 
 } 
 
int main()
{
	string s1;
	getline(cin,s1);
	cout<<count2(s1)<<endl;
    return 0;
}
~~~















