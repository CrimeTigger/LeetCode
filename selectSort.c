#define MAXSIZE                                                                                 \
    10 typedef struct                                                                           \
    {                       /* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */ \
        int r[MAXSIZE + 1]; /* ���ڼ�¼˳���ĳ��� */                                \
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