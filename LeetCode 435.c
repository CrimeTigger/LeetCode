int cmp(const void *a, const void *b)
{
    // return (*((int**)a))[0]>(*((int**)b))[0];
    return ((*((int **)a))[0] > (*((int **)b))[0]); // 左边界排序
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (intervalsSize == 0)
        return 0;
    int count = 0;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    for (int i = 0; i < intervalsSize; i++)
    {
        if (intervals[i][0] < intervals[i - 1][1]) // 重叠情况 记录重叠区间
        {
            count++;
            intervals[i][1] = fmin(intervals[i][1], intervals[i - 1][1]);
        }
    }
    return count;
}