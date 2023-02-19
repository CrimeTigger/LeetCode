/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* odd=list1;
    struct ListNode* even=list2;
    struct no
    struct ListNode* newList=malloc(sizeof(ListNode)*odd);
    newList->next;
    if(list1==NULL||list2==NULL){
        return NULL;
    }
    while(odd->next && even->next){
        if(odd->val<=even->val){
            newList->next=odd;
            odd=odd->next;
            
        }else{
            newList->next=even;
            even=even->next;
           
        }
        newList=newList->next;
    }
    newList->next=odd==NULL? even:odd;
    return newList->next;
}