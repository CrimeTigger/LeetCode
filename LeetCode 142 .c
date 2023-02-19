/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast){
        slow=slow->next;
        if(fast->next==NULL){
            return NULL;
        }
        fast=fast->next->next;
        if(slow==fast){
            struct ListNode*p=head;
            while(p!=slow){
                p=p->next;
                slow=slow->next;
                }
            
            return p;
        }
    }
    return NULL;
}