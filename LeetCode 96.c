// 开辟dp数组
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
    // 开辟dp数组
    int *dp = initDP(n);
    // 将dp[0]设为1
    dp[0] = 1;

    int i, j;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            // 递推公式：dp[i] = dp[i] + 根为j时左子树种类个数 * 根为j时右子树种类个数
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}