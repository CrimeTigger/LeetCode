/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre=NULL;
    struct ListNode* curr=head;
    while(curr){
       struct ListNode* temp = curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp;
    }
    return pre;
}