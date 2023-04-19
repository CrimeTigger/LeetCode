// dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]。

// 操作一：word1删除一个元素 即 dp[i][j] = dp[i - 1][j] + 1;
// 操作二：word2删除一个元素 即 dp[i][j] = dp[i][j - 1] + 1;  word2添加一个元素，相当于word1删除一个元素，都是一次
// 操作三：替换元素  dp[i][j] = dp[i - 1][j - 1] + 1;
int minDistance(char *word1, char *word2)
{
    int length1 = strlen(word1);
    int length2 = strlen(word2);
    int dp[length1 + 1][length2 + 1];
    for (int i = 0; i <= length1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= length2; j++)
        dp[0][j] = j;
    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[length1][length2];
}