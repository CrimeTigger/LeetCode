//// dp[i][0]代表第i天持有股票的最大收益
// dp[i][1]代表第i天不持有股票的最大收益
int maxProfit(int *prices, int pricesSize)
{
    if (prices == 0)
        return 0;
    int dp[pricesSize + 1][2];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = fmax(dp[i - 1][0], -prices[i]);
        dp[i][1] = fmax(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[pricesSize - 1][1];
}