/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
环形链表的思路是设置快慢指针。快指针进入环，然后循环。当快慢指针相遇，就说明存在环
*/
bool hasCycle(struct ListNode *head) {
    //注意：这里先判断头结点和下一个结点是否为空
    if(head == NULL || head->next == NULL){
        return false;
    }

    struct ListNode* node1;
    struct ListNode* node2;
    
    //为了判断条件，设置快指针快一步
    node1 = head;
    node2 = head->next;
   
    while(node2 != node1){
        if(node2 == NULL || node2->next == NULL){ //判断后面是否存在结点
            return false;
        }
        node1 = node1->next;
        node2 = node2->next->next;
    }

    return true;
}
