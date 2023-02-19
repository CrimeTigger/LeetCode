/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *pre = dummyHead;
    while (pre->next)
    {
        if (pre->next->val == val)
        {
            pre->next = pre->next->next;
        }
        else
        {
            pre = pre->next;
        }
    }
    return dummyHead->next;
}