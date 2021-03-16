/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
关键是当快慢指针第一次相遇后，下一次相遇经过的结点数刚好是需要进入环的结点数。这个需要通过计算得出

*/
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

//     if(head == NULL || head->next == NULL){
//         return NULL;
//     }

    while(fast != NULL){  //终止条件
        slow = slow->next;
        
        if(fast->next == NULL){ //需要判断下一个结点是否为空
            return NULL;
        }

        fast = fast->next->next;

        if(fast == slow){  //如果快慢指针相遇了，需要设置一个新的指针
            struct ListNode* p;
            p = head;
            while(p != slow){
                p = p->next;
                slow = slow->next;
            }
            return p;
        } 
    }
    return NULL;
}
