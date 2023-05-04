int *path;
int pathTop;
int **ans;
int ansTop;
// 记录二维数组中每个一维数组的长度
int *length;
// 将当前path数组复制到ans中
void copy()
{
    int *tempPath = (int *)malloc(sizeof(int) * pathTop);
    int i;
    for (i = 0; i < pathTop; i++)
    {
        tempPath[i] = path[i];
    }
    ans = (int **)realloc(ans, sizeof(int *) * (ansTop + 1));
    length[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

void backTracking(int *nums, int numsSize, int startIndex)
{
    // 收集子集，要放在终止添加的上面，否则会漏掉自己
    copy();
    // 剩余集合为空的时候，就是叶子节点。
    if (startIndex >= numsSize)
    {
        return;
    }
    int j;
    for (j = startIndex; j < numsSize; j++)
    {
        // 将当前下标数字放入path中
        path[pathTop++] = nums[j];
        backTracking(nums, numsSize, j + 1);
        // 回溯
        pathTop--;
    }
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // 初始化辅助变量
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(0);
    length = (int *)malloc(sizeof(int) * 1500);
    ansTop = pathTop = 0;
    // 进入回溯
    backTracking(nums, numsSize, 0);
    // 设置二维数组中元素个数
    *returnSize = ansTop;
    // 设置二维数组中每个一维数组的长度
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}