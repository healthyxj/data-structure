/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
涉及到链表的操作，最好先在纸上画出步骤，再写程序
题目要求反转链表，通常的解决方法是定义pre、cur、nex三个指针，然后改变指向完成反转
*/

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre; //最好分开来定义指针
    struct ListNode* p = head;  //定义一个临时指针指向头指针
    struct ListNode* nex;
    pre = NULL; //先将前指针指向空

    while(p){
        nex = p->next; //定义一个nex指针，用于遍历整个链表
        p->next = pre;  //完成局部反转
        pre = p;
        p = nex;  //用于最后空结点的判断
    }
    
    return pre;
}
