// dp[i][j]�� i��ʾ��i�죬jΪ [0 - 4] ���״̬��dp[i][j]��ʾ��i��״̬j��ʣ����ֽ�
//  һ��һ���������״̬��

// 0 û�в��� ����ʵ����Ҳ���Բ��������״̬��
// 1 ��һ�γ��й�Ʊ
// 2 ��һ�β����й�Ʊ
// 3 �ڶ��γ��й�Ʊ
// 4 �ڶ��β����й�Ʊ
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