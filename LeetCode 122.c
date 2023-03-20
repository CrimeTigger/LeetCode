// 贪心
int maxProfit(int *prices, int pricesSize)
{
    int result = 0;
    int i;
    // 从第二个元素开始遍历数组，与之前的元素进行比较
    for (i = 1; i < pricesSize; ++i)
    {
        // 若该元素比前面元素大，则说明有利润。代表买入
        if (prices[i] > prices[i - 1])
            result += prices[i] - prices[i - 1];
    }
    return result;
}

// 动态规划
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int *prices, int pricesSize)
{
    int dp[pricesSize][2];
    dp[0][0] = 0 - prices[0];
    dp[0][1] = 0;

    int i;
    for (i = 1; i < pricesSize; ++i)
    {
        // dp[i][0]为i-1天持股的钱数/在第i天用i-1天的钱买入的最大值。
        // 若i-1天持股，且第i天买入股票比i-1天持股时更亏，说明应在i-1天时持股
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        // dp[i][1]为i-1天不持股钱数/在第i天卖出所持股票dp[i-1][0] + prices[i]的最大值
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    // 返回在最后一天不持股时的钱数（将股票卖出后钱最大化）
    return dp[pricesSize - 1][1];
}