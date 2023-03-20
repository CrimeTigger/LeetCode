// 大餅乾先餵飽大胃口的
int cmp(int *a, int *b)
{
    return *a - *b;
}
int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int count = 0;
    int start = sSize - 1;
    for (int i = gSize - 1; i >= 0; i--)
    {
        if (start >= 0 && s[start] >= g[i])
        {
            count++;
            start--;
        }
    }
    return count;
}

// 小餅乾先餵飽小胃口的
int cmp(int *a, int *b)
{
    return *a - *b;
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    if (sSize == 0)
        return 0;

    // 将两个数组排序为升序
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int numFedChildren = 0;
    int i = 0;
    for (i = 0; i < sSize; ++i)
    {
        if (numFedChildren < gSize && g[numFedChildren] <= s[i])
            numFedChildren++;
    }
    return numFedChildren;
}