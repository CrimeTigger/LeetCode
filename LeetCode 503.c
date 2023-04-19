/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 不扩充nums，而是在遍历的过程中模拟走了两边nums
 * i%(numsSize*2)取余 获得索引
 */
int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    if (numsSize == 0)
        return numsSize;
    int *result = malloc(numsSize * sizeof(int));
    memset(result, -1, sizeof(result));
    *returnSize = numsSize;
    int stack[numsSize + 1];
    int top = 0;
    for (int i = 0; i < numsSize * 2; i++)
    {
        while (top > 0 && nums[i % (numsSize * 2)] > nums[stack[top - 1]])
        {
            result[stack[top - 1]] = nums[i % (numsSize * 2)];
            top--;
        }
        stack[top++] = i % (numsSize * 2);
    }
    return result;
}