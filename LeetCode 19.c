/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dummHead = malloc(sizeof(struct ListNode));
    dummHead->next = head;
    struct ListNode *fast = dummHead;
    struct ListNode *slow = dummHead;
    while (n-- && fast)
    {
        fast = fast->next;
    }
    fast = fast->next;// fast再提前走一步，因为需要让slow指向删除节点的上一个节点
    while (slow && fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummHead->next;
}