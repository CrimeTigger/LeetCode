

int **res;
int *paths;
int resTop;
int pathTop;
void backtracking(int k, int n, int sum, int startIndex)
{
    if (sum > n) // 已选元素总和如果已经大于n（图中数值为4）了，那么往后遍历就没有意义了，直接剪掉
        return;
    if (pathTop == k)
    {
        if (sum == n)
        {
            int *temp = malloc(sizeof(int) * (k + 1));
            for (int i = 0; i < k; i++)
            {
                temp[i] = paths[i];
            }
            res[resTop++] = temp;
        }
        return;
    }
    for (int i = startIndex; i <= 9 - (k - pathTop) + 1; i++) // 剪枝
    {
        sum += i;
        paths[pathTop++] = i;
        backtracking(k, n, sum, i + 1);
        sum -= i;
        pathTop--;
    }
}
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
    // path数组存储符合条件的结果
    paths = (int *)malloc(sizeof(int) * k);
    // ans二维数组存储符合条件的结果数组的集合。（数组足够大，避免极端情况）
    res = (int **)malloc(sizeof(int *) * 10000);
    pathTop = resTop = 0;

    // 回溯算法
    backtracking(k, n, 0, 1);
    // 最后的返回大小为res数组大小
    *returnSize = resTop;
    // returnColumnSizes数组存储ans二维数组对应下标中一维数组的长度（都为k）
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    for (i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = k;
    }
    // 返回ans二维数组
    return res;
}