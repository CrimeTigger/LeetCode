/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node *copyRandomList(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    for (struct Node *node = head; node != NULL; node¡ª > next->next)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->val = node->val;
        newNode->next = node->next;
        node->next = newNode;
    }
    for (struct Node *node = head; node != NULL; node->next->next)
    {
        struct Node *newNode = node->next;
        newNode->random = node->random != NULL ? node->random->next : NULL;
    }
    struct Node *newHead = head->next;
    for (struct Node *node = head; node != NULL; node¡ª > next->next)
    {
        struct Node *newNode = node->next;
        node->next = node->next;
        newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
    }
    return newHead;
}