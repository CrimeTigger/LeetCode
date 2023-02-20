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
void BubbleSort(SqList *L)
{
    int i, j;
    bool flag = true;
    for (int i = 0; i < L->length-1; i++)//ѭ��n��
    {
        flag = false;
        for (int j = 0; j<L->length-1-i; j++)//�������������ֵ����
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
                flag = true;
            }
        }
    }
}