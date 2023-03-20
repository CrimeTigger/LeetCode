// /**
//  * Return an array of arrays of size *returnSize.
//  * The sizes of the arrays are returned as *returnColumnSizes array.
//  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
//  * ����ı�����ʵ�����ж��ص���������
//  */
// int cmp(const void *a, const void *b)
// {
//     return (*((int **)a))[0] > (*((int **)b))[0];
// }

// int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
// {
//     if (intervalsSize == 0)
//         return intervals;
//     qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp); // �����������е��������価���ܵ��ص���һ��
//     int **res = (int **)malloc(sizeof(int *) * intervalsSize);
//     *returnSize = 0;
//     res[(*returnSize)++] = intervals[0];
//     for (int i = 1; i < intervalsSize; i++)
//     {
//         if (res[(*returnSize)][1] >= intervals[i][0])
//         {
//             res[(*returnSize)][1] = fmax(intervals[i][1], res[(*returnSize)][1]);
//         } // ��ʵ�����úϲ��������߽���ұ߽磬��Ϊһ���µ����䣬���뵽result������Ϳ����ˡ����û�кϲ��Ͱ�ԭ������뵽result����
//         else
//         {
//             res[(*returnSize)++] = intervals[i];
//         }
//     }
//     return res;
// }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * ����ı�����ʵ�����ж��ص���������
 */
int cmp(const void *a, const void *b)
{
    return (*((int **)a))[0] > (*((int **)b))[0];
}
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    if (intervalsSize == 0)
        return intervalsSize;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int **result = (int **)malloc(sizeof(int *) * intervalsSize);
    int resTop = 0;
    // *returnSize=0;
    result[resTop++] = intervals[0];
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] < result[resTop - 1])
        {
            result[resTop - 1][1] = fmax(intervals[i][1], result[resTop - 1][1]);
        }
        else
        {
            result[resTop++] = intervals[i];
        }
    }
    *returnSize = resTop;
    return result;
}