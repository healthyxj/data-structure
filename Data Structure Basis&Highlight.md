 

切题四件套

* Clarification
  * 考虑有无陷阱
* Possible solutions
  * compare(times/space)，<b>找出最优解</b>
  * optimal(加强)
* Coding(多写)
  * 坚持、刻意练习
  * 练习缺陷、弱点的地方
* Test cases

LeetCode：https://leetcode-cn.com/problemset/all/

可以点社区题解进行学习

# 一、复杂度

## Big O notation

时间复杂度，通俗来说是<b>计算次数</b>

O(1) 常数复杂度

O(log n) 对数复杂度

O(n)线性时间复杂度

O(n^2)平方

O(n^3)立方

O(2^n)指数——斐波那契数列，递归算法

O(n!)阶乘

~~~java
//O(log n)
for (int i = 1;i < n;i = i*2){
    System.out.println("Hey-I'm busy looking at " + i);
}

//O(k^n)
for (int i = 1;i <= Math.pow(2,n);i++){
    System.out.println("Hey-I'm busy looking at " + i);
}

//O(n!)
for (int i = 1;i <= factorial(n);i++){
    System.out.println("Hey-I'm busy looking at " + i);
}
~~~

常见四种算法的时间复杂度

Binary Seasrch: 	O(log n)

Binary Tree Traversal:	O(n)

Optimal Sorted Matrix:	O(n)

Merge sort:  	O(n*log n)

# 二、数组与链表

数组是内存中连续的一段。 

数组插入和删除需要挪动数据，O(n)。数组查询O(1)

单链表插入和删除O(1)，链表查询O(n)。

