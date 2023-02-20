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
void BubbleSort(SqList *L)
{
    int i, j;
    bool flag = true;
    for (int i = 0; i < L->length-1; i++)//循环n次
    {
        flag = false;
        for (int j = 0; j<L->length-1-i; j++)//两两交换，最大值沉底
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
                flag = true;
            }
        }
    }
}