int coinChange(int *coins, int coinsSize, int amount)
{
    int dp[coinsSize + 1];
    memset(dp, INT_MAX, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++)
    { // ������Ʒ
        for (int j = coins[i]; j <= amount; j++)
        { // ��������
            if (dp[j - coins[i]] != INT_MAX)
            { // ���dp[j - coins[i]]�ǳ�ʼֵ������
                dp[j] = fmin(dp[j - coins[i]], dp[j]);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}