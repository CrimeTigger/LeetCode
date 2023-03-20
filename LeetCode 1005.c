// 局部最优：让绝对值大的负数变为正数，当前数值达到最大，整体最优：整个数组和达到最大

int cmp(int *a, int *b)
{
    return fabs(*b) - fabs(*a);
}

int largestSumAfterKNegations(int *nums, int numsSize, int k)
{
    int result = 0;
    // 将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
    qsort(nums, numsSize, sizeof(int), cmp);
    // 从前向后遍历，遇到负数将其变为正数，同时K--
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 && k > 0)
        {
            nums[i] *= -1;
            k--;
        }
    }
    // 如果K还大于0，那么反复转变数值最小的元素，将K用完
    if (k % 2 == 1)
        nums[numsSize - 1] *= -1;
    // 求和
    for (int j = 0; j < numsSize; j++)
    {
        result += nums[j];
    }
    return result;
}