int fib(int n)
{
    // ��n <= 1ʱ������n
    if (n <= 1)
        return n;
    // ��̬����һ��int���飬��СΪn+1
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    // ����0��λΪ0��1��ΪΪ1
    dp[0] = 0;
    dp[1] = 1;

    // ��ǰ����������(i=2; i <= n; ++i),�±�Ϊnʱ��Ԫ��Ϊdp[i-1] + dp[i-2]
    int i;
    for (i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}