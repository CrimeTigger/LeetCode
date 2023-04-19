int combinationSum4(int *nums, int numsSize, int target)
{
    int dp[target + 1]; // dp[i]: 凑成目标正整数为i的排列个数为dp[i]
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i <= target; i++) // target（背包）放在外循环，将nums（物品）放在内循环，内循环从前到后遍历。
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
            {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}