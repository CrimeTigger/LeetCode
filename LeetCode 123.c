// dp[i][j]中 i表示第i天，j为 [0 - 4] 五个状态，dp[i][j]表示第i天状态j所剩最大现金。
//  一天一共就有五个状态，

// 0 没有操作 （其实我们也可以不设置这个状态）
// 1 第一次持有股票
// 2 第一次不持有股票
// 3 第二次持有股票
// 4 第二次不持有股票
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize == 0)
        return 0;
    int dp[pricesSize + 1][5];
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][1] = fmax(dp[i - 1][1], -prices[i]);
        dp[i][2] = fmax(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = fmax(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = fmax(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[pricesSize - 1][4];
}