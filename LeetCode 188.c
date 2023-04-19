int maxProfit(int k, int *prices, int pricesSize)
{
    if (pricesSize == 0)
        return 0;
    int dp[pricesSize + 1][2 * k + 1];
    for (int j = 1; j < 2 * k; j += 2)
    {
        dp[0][j] = -prices[0];
    }
    for (int i = 1; i < pricesSize; i++)
    {
        for (int j = 0; j < 2 * k - 1; j += 2)
        {
            dp[i][j + 1] = fmax(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
            dp[i][j + 2] = fmax(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
        }
    }
    return dp[pricesSize - 1][2 * k];
}