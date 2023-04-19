// dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。

//当s[i - 1] 与 t[j - 1]相等时，dp[i][j]可以有两部分组成。

// 一部分是用s[i - 1]来匹配，那么个数为dp[i - 1][j - 1]。即不需要考虑当前s子串和t子串的最后一位字母，所以只需要 dp[i-1][j-1]。

// 一部分是不用s[i - 1]来匹配，个数为dp[i - 1][j]。
// 当s[i - 1] 与 t[j - 1]不相等时，dp[i][j]只有一部分组成，不用s[i - 1]来匹配（就是模拟在s中删除这个元素），即：dp[i - 1][j]
int numDistinct(char *s, char *t)
{
    int length1 = strlen(s);
    int length2 = strlen(t);
    int dp[length1 + 1][length2 + 1];
    for (int i = 0; i < length1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < length2; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[length1][length2];
}