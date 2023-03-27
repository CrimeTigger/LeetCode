
// ��ʵ���Դ�1����j��Ȼ�������������õ�dp[i].

// һ����j * (i - j) ֱ����ˡ�

// һ����j * dp[i - j]���൱���ǲ��(i - j)
int integerBreak(int n)
{
    int *dp = malloc(sizeof(int) * (n + 1));
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i / 2; j++)
        {
            dp[i] = fmax(dp[i], fmax(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}