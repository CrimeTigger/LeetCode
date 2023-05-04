/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *path;
int pathTop;
int **ans;
int ansTop;
// ��path��Ԫ�ؿ�����ans��
void copy()
{
    int *temp = malloc(sizeof(int) * pathTop);
    memcpy(temp, path, sizeof(int) * pathTop);
    ans[ansTop++] = temp;
}
void backTracking(int *nums, int numsSize, int *used)
{
    if (pathTop == numsSize) // ��path��Ԫ�ظ�������numsԪ�ظ�������nums����ans��
    {
        copy();
        return;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (used[i]) // ����ǰ�±���Ԫ����ʹ�ù�����������ǰԪ��
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
    // ��used������Ԫ�ض���0
    memset(used, 0, sizeof(int) * numsSize);
    ansTop = pathTop = 0;

    backTracking(nums, numsSize, used);

    // ����path��ans����ĳ���
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    return ans;
}