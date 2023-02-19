#include <stdio.h>
#include <stdlib.h>
/* 随机产生n个元素的值，建立带表头结点的单链   线性表L（头插法） */
typedef struct Node
{
    int data;
    struct Node *next;
} LinkList;

LinkList *CreateListHead(LinkList *L, int n)
{
    LinkList *p;
    int i;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = rand() % 100 + 1;
        p->next = L->next;
        L->next = p->next;
        /* code */
    }

    return L;
}
void readList(LinkList *L, int n)
{
    LinkList *p;
    int i;
    p = L->next;
    while (p && i < n)
    {
        p = p->next;
        ++i; /* code */
    }
    if (!p || i > n)
    {
        return;
        /* code */
    }
    printf("%d", p->data);
}

#define MAXSIZE 1000;
typedef struct
{
    int data;
    int cur;
} Component;

Component *StaticLinkList[MAXSIZE];

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[1].cur;
    }

    return i;
}
// Status ListInsert(StaticLinkList L, int i, int data)
// {
// }

int main()
{
    LinkList *L;
    L = CreateListHead(L, 2);
    readList(L, 1);
}