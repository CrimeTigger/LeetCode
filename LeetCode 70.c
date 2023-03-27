int climbStairs(int n)
{
    // 若n<=2，返回n
    if (n <= 2)
        return n;
    // 初始化dp数组，数组大小为n+1
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    // 从前向后遍历数组，dp[i] = dp[i-1] + dp[i-2]
    int i;
    for (i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // 返回dp[n]
    return dp[n];
}

// 优化空间复杂度：
int climbStairs(int n)
{
    // 若n<=2，返回n
    if (n <= 2)
        return n;
    // 初始化dp数组，数组大小为3
    int *dp = (int *)malloc(sizeof(int) * 3);
    dp[1] = 1, dp[2] = 2;

    // 只记录前面两个台阶的状态
    int i;
    for (i = 3; i <= n; ++i)
    {
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    // 返回dp[2]
    return dp[2];
}