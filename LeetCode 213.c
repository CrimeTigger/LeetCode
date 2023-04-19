int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    int result1 = robRange(nums, 0, numsSize - 2, numsSize); // ���ǰ�����Ԫ�أ�������βԪ��
    int result2 = robRange(nums, 1, numsSize - 1, numsSize); // ���ǰ���βԪ�أ���������Ԫ��
    return fmax(result1, result2);
}

int robRange(int *nums, int start, int end, int numsSize)
{
    if (start == end)
        return nums[start];
    int dp[numsSize];
    dp[start] = nums[start];
    dp[start + 1] = fmax(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++)
    {
        dp[i] = fmax(dp[i - 2] + nums[i], dp[i - 1]);
    }   
    return dp[end];
}