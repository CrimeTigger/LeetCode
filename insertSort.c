#define MAXSIZE                                                                                 \
    10 typedef struct                                                                           \
    {                       /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */ \
        int r[MAXSIZE + 1]; /* 用于记录顺序表的长度 */                                \
        int length;                                                                             \
    } SqList;

void InsertSort(SqList *L)
{
    for (int i = 1; i < SqList->length - 1; i++)
    {
        int temp = SqList->r[i]; // 临时变量存r[i]
        if (SqList->r[i] < SqList->r[i - 1])
        {
            for (int j = i - 1; j >= 0 && SqList->r[j] > temp; j--)//内循环倒着
            {
                SqList->r[j + 1] = SqList->r[j];
                SqList->r[j] = temp;
            }
        }
    }
}