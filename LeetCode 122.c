// ̰��
int maxProfit(int *prices, int pricesSize)
{
    int result = 0;
    int i;
    // �ӵڶ���Ԫ�ؿ�ʼ�������飬��֮ǰ��Ԫ�ؽ��бȽ�
    for (i = 1; i < pricesSize; ++i)
    {
        // ����Ԫ�ر�ǰ��Ԫ�ش���˵�������󡣴�������
        if (prices[i] > prices[i - 1])
            result += prices[i] - prices[i - 1];
    }
    return result;
}

// ��̬�滮
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxProfit(int *prices, int pricesSize)
{
    int dp[pricesSize][2];
    dp[0][0] = 0 - prices[0];
    dp[0][1] = 0;

    int i;
    for (i = 1; i < pricesSize; ++i)
    {
        // dp[i][0]Ϊi-1��ֹɵ�Ǯ��/�ڵ�i����i-1���Ǯ��������ֵ��
        // ��i-1��ֹɣ��ҵ�i�������Ʊ��i-1��ֹ�ʱ������˵��Ӧ��i-1��ʱ�ֹ�
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        // dp[i][1]Ϊi-1�첻�ֹ�Ǯ��/�ڵ�i���������ֹ�Ʊdp[i-1][0] + prices[i]�����ֵ
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    // ���������һ�첻�ֹ�ʱ��Ǯ��������Ʊ������Ǯ��󻯣�
    return dp[pricesSize - 1][1];
}