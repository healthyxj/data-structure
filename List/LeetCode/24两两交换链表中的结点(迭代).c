/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode Thead;  //注意是没有*，因此下面的next用的是.
    Thead.next = head;
    struct ListNode* tmp = &Thead;  //定义一个tmp临时指针，将Thead的地址值存入tmp
  
    while(tmp->next != NULL && tmp->next->next != NULL){  //结束的时候是少于两个结点的情况
        struct ListNode* node1; //最好分开创建指针
        struct ListNode* node2;
      
        node1 = tmp->next;  //让新建的指针分别指向tmp的后两个结点
        node2 = tmp->next->next;
        
      //开始三个结点(tmp, node1, node2)进行排序，让第一个结点指向第三个结点
        tmp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        tmp = node1;  //往后移，方便新一轮的交换
    }
    return Thead.next;
}
