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
