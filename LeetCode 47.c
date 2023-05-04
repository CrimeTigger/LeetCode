/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 临时数组
int *path;
// 返回数组
int **ans;
int *used;
int pathTop, ansTop;
void cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}
// 拷贝path到ans中
void copy()
{
    int *temp = malloc(sizeof(int) * pathTop);
    memcpy(temp, path, sizeof(int) * pathTop);
    ans[ansTop++] = temp;
}

void backTracking(int *used, int *nums, int numsSize)
{
    if (pathTop == numsSize)
    {
        copy();
        return;
    }
    for (int i = 0; i < numsSize; i++)
    { // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
      // used[i - 1] == false，说明同一树层nums[i - 1]使用过
      // 如果同一树层nums[i - 1]使用过则直接跳过
        if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
            continue;
        if (used[i] == false)
        {
            used[i] = true;
            path[pathTop++] = nums[i];
            backTracking(used, nums, numsSize);
            used[i] = false;
            pathTop--;
        }
    }
}
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    pathTop = ansTop = 0;
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(sizeof(int *) * 1000);
    // 初始化used辅助数组
    used = (int *)malloc(sizeof(int) * numsSize);
    memset(used, 0, sizeof(int) * numsSize);

    backTracking(used, nums, numsSize);

    // 设置返回的数组的长度
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int z;
    for (z = 0; z < ansTop; z++)
    {
        (*returnColumnSizes)[z] = numsSize;
    }
    return ans;
}