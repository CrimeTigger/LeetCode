int numSquares(int n)
{
    int dp[n + 1]; // dp[j]：和为j的完全平方数的最少数量为dp[j]
    memset(dp, INT_MAX, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i * i < n; i++)
    {
        for (int j = i * i; j <= n; j++)
        {
            dp[j] = fmin(dp[j], dp[j - i * i] + 1);
        }
    }
    return dp[n];
}