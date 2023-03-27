
// 其实可以从1遍历j，然后有两种渠道得到dp[i].

// 一个是j * (i - j) 直接相乘。

// 一个是j * dp[i - j]，相当于是拆分(i - j)
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