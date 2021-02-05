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
