/**
 * Note: The returned array must be malloced, assume caller calls free().
 * ������nums�������ڱ����Ĺ�����ģ����������nums
 * i%(numsSize*2)ȡ�� �������
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