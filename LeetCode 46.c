/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *path;
int pathTop;
int **ans;
int ansTop;
// 将path中元素拷贝到ans中
void copy()
{
    int *temp = malloc(sizeof(int) * pathTop);
    memcpy(temp, path, sizeof(int) * pathTop);
    ans[ansTop++] = temp;
}
void backTracking(int *nums, int numsSize, int *used)
{
    if (pathTop == numsSize) // 若path中元素个数等于nums元素个数，将nums放入ans中
    {
        copy();
        return;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (used[i]) // 若当前下标中元素已使用过，则跳过当前元素
            continue;
        used[i] = true;
        path[pathTop++] = nums[i];
        backTracking(nums, numsSize, used);
        used[i] = false;
        pathTop--;
    }
}
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(sizeof(int *) * 1000);
    int *used = (int *)malloc(sizeof(int) * numsSize);
    // 将used数组中元素都置0
    memset(used, 0, sizeof(int) * numsSize);
    ansTop = pathTop = 0;

    backTracking(nums, numsSize, used);

    // 设置path和ans数组的长度
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}