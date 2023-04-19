//// dp[i][0]�����i����й�Ʊ���������
// dp[i][1]�����i�첻���й�Ʊ���������
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