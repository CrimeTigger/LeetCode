#define MAXSIZE                                                                                 \
    10 typedef struct                                                                           \
    {                       /* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */ \
        int r[MAXSIZE + 1]; /* ���ڼ�¼˳���ĳ��� */                                \
        int length;                                                                             \
    } SqList;

void InsertSort(SqList *L)
{
    for (int i = 1; i < SqList->length - 1; i++)
    {
        int temp = SqList->r[i]; // ��ʱ������r[i]
        if (SqList->r[i] < SqList->r[i - 1])
        {
            for (int j = i - 1; j >= 0 && SqList->r[j] > temp; j--)//��ѭ������
            {
                SqList->r[j + 1] = SqList->r[j];
                SqList->r[j] = temp;
            }
        }
    }
}