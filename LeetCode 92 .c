/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->val = -1;
    dummyNode->next = head;
    struct ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++)
    {
        pre = pre->next;
    }
    struct ListNode *cur = pre->next;
    for (int i = 0; i < right - left; i++)
    {
        struct ListNode *next = cur->next;
        cur->next = cur->next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummyNode->next;
}