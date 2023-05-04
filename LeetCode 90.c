int *path;
int pathTop;
int **ans;
int ansTop;
// 负责存放二维数组中每个数组的长度
int *lengths;
// 快排cmp函数
int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

// 复制函数，将当前path中的元素复制到ans中。同时记录path长度
void copy()
{
    int *tempPath = (int *)malloc(sizeof(int) * pathTop);
    int i;
    for (i = 0; i < pathTop; i++)
    {
        tempPath[i] = path[i];
    }
    ans = (int **)realloc(ans, sizeof(int *) * (ansTop + 1));
    lengths[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

void backTracking(int *nums, int numsSize, int startIndex, int *used)
{
    // 首先将当前path复制
    copy();
    // 若startIndex大于数组最后一位元素的位置，返回
    if (startIndex >= numsSize)
        return;

    int i;
    for (i = startIndex; i < numsSize; i++)
    {
        // 对同一树层使用过的元素进行跳过
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            continue;
        path[pathTop++] = nums[i];
        used[i] = true;
        backTracking(nums, numsSize, i + 1, used);
        used[i] = false;
        pathTop--;
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // 声明辅助变量
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(0);
    lengths = (int *)malloc(sizeof(int) * 1500);
    int *used = (int *)malloc(sizeof(int) * numsSize);
    pathTop = ansTop = 0;

    // 排序后查重才能生效
    qsort(nums, numsSize, sizeof(int), cmp);
    backTracking(nums, numsSize, 0, used);

    // 设置一维数组和二维数组的返回大小
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = lengths[i];
    }
    return ans;
}