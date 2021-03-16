/*
链表的常用方法有递归和迭代
递归三步
1、找终止条件：这题是链表结束或者只剩一个结点
2、找返回值：返回给上一层的递归值应该是已经排列好的链表
3、每一次的过程：由于递归重复做一件事，只需考虑每一步的步骤。设交换的两个结点为first和next，next应该接收上一对交换的链表。所以可以看成是三个结点在做交换。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    
  //首先判断终止条件，根据之前的分析，容易写出
    if(head == NULL || head->next == NULL){ //这两个前后不能够交换位置
        return head;
    }

  //定义一个结点，指向头指针的下一个结点，形成一对
    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);  //对第三个结点进行判断
    newHead->next = head; //交换位置
    return newHead; //返回头结点
}
