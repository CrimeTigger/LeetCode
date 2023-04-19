int coinChange(int *coins, int coinsSize, int amount)
{
    int dp[coinsSize + 1];
    memset(dp, INT_MAX, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++)
    { // 遍历物品
        for (int j = coins[i]; j <= amount; j++)
        { // 遍历背包
            if (dp[j - coins[i]] != INT_MAX)
            { // 如果dp[j - coins[i]]是初始值则跳过
                dp[j] = fmin(dp[j - coins[i]], dp[j]);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}