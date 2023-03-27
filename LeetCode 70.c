int climbStairs(int n)
{
    // ��n<=2������n
    if (n <= 2)
        return n;
    // ��ʼ��dp���飬�����СΪn+1
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    // ��ǰ���������飬dp[i] = dp[i-1] + dp[i-2]
    int i;
    for (i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // ����dp[n]
    return dp[n];
}

// �Ż��ռ临�Ӷȣ�
int climbStairs(int n)
{
    // ��n<=2������n
    if (n <= 2)
        return n;
    // ��ʼ��dp���飬�����СΪ3
    int *dp = (int *)malloc(sizeof(int) * 3);
    dp[1] = 1, dp[2] = 2;

    // ֻ��¼ǰ������̨�׵�״̬
    int i;
    for (i = 3; i <= n; ++i)
    {
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    // ����dp[2]
    return dp[2];
}