/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 合并两条链
struct ListNode *mergetwolists(struct ListNode *head1, struct ListNode *head2)
{
    struct ListNode *p1 = head1;
    struct ListNode *p2 = head2;
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    while (p1 && p2)
    {
        if (p1->val < p2->val)
        {
            tail->next = p1;
            p1 = p1->next;
        }
        else
        {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    tail->next = p1 == NULL ? p2 : p1;
    return head->next;
}
//分解链
struct ListNode *dividelists(struct ListNode **lists, int left, int right)
{
    if (left == right)
    {
        return lists[left];
    }
    int mid = left + (right - left) / 2;

    return mergetwolists(dividelists(lists, left, mid), dividelists(lists, mid + 1, right));
}

struct ListNode *mergeKLists(struct ListNode *lists, int listsSize)
{
    int left = 0;
    int right = listsSize - 1;
    return dividelists(lists, left, right);
}