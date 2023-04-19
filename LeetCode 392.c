// dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]。

bool isSubsequence(char *s, char *t)
{
    int length1 = strlen(s);
    int length2 = strlen(t);
    int dp[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1]; // if (s[i - 1] != t[j - 1])，此时相当于t要删除元素，t如果把当前元素t[j - 1]删除，那么dp[i][j] 的数值就是 看s[i - 1]与 t[j - 2]的比较结果了，即：dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[length1][length2] == length1; // dp[i][j]表示以下标i-1为结尾的字符串s和以下标j-1为结尾的字符串t 相同子序列的长度，所以如果dp[s.size()][t.size()] 与 字符串s的长度相同说明：s与t的最长相同子序列就是s，那么s 就是 t 的子序列。
}