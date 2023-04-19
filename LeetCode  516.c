// dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。
int longestPalindromeSubseq(char *s)
{
    int length = strlen(s);
    int dp[length + 1][length + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < length; i++) // 初始化 当i与j相同，那么dp[i][j]一定是等于1的，即：一个字符的回文子序列长度就是1。
        dp[i][i] = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2; // 如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]); // 如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入 并不能增加[i,j]区间回文子序列的长度，那么分别加入s[i]、s[j]看看哪一个可以组成最长的回文子序列。
            }
        }
    }
    return dp[0][length - 1];
}