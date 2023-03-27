// ����dp����
int *initDP(int n)
{
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int i;
    for (i = 0; i <= n; ++i)
        dp[i] = 0;
    return dp;
}

int numTrees(int n)
{
    // ����dp����
    int *dp = initDP(n);
    // ��dp[0]��Ϊ1
    dp[0] = 1;

    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            // ���ƹ�ʽ��dp[i] = dp[i] + ��Ϊjʱ������������� * ��Ϊjʱ�������������
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}