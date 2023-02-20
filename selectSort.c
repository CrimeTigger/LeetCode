#define MAXSIZE                                                                                 \
    10 typedef struct                                                                           \
    {                       /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */ \
        int r[MAXSIZE + 1]; /* 用于记录顺序表的长度 */                                \
        int length;                                                                             \
    } SqList;

struct swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
void SelectSort(SqList *L)
{
    int i, j, min;
    for (int i = 0; i < SqList->length - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < SqList->length - 1; j++)
        {
            if (SqList->r[min] > SqList->[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(L, i, min);
        }
    }
}