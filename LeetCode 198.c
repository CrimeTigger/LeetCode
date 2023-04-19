// dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        dp[i] = fmax(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[numsSize - 1];
}