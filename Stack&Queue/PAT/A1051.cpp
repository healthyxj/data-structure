#include<cstdio>
#include<stack>

using namespace std;

#define MaxSize 1005

stack<int> st;

/*
题目要求根据m, n, k。确定输入的序列是否合法
思路：考虑用STL中的stack。
读取mnk的值，对于每一组序列分别进行检验。
检验过程，首先要确认当前的栈是否为空，然后用一个数组读入该组序列。
然后与标准的序列进行比较，比较的是栈顶元素是否与序列的元素相等，如果有就弹出栈顶元素。否则就不断入栈。
如果超过了栈的容量，就判断序列不合法，到最后如果栈为空，并且没有不合法的情况就输出YES。
*/


int arr[MaxSize];

int main(){
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
  
    while(k--){
        while(!st.empty()){  //判断栈是否为空，如果为空，就不断弹出栈中元素
            st.pop();
        }
    
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
        }
    
        int tmp = 1;
        bool flag = true;
    
        for(int i = 1; i <= n; i++){
            st.push(i); //让整数进栈
      
            if(st.size() > m){  //如果超过了给定的容量，就定义为非法
                flag = false;
                break;
            }
      
            while(!st.empty() && st.top() == arr[tmp]){
                st.pop();
                tmp++;
            }
        }
        //printf("语句执行了!");

        if(st.empty() == true && flag == true){ //st.empty()表示栈为空，序列合法的条件是栈为空且flag为true
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    } 
  
  
    return 0;
}
