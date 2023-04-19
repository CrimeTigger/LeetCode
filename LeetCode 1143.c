// 本题和动态规划：718. 最长重复子数组区别在于这里不要求是连续的了，但要有相对顺序，即："ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
// dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]

int longestCommonSubsequence(char *text1, char *text2)
{
    int length1 = strlen(text1);
    int length2 = strlen(text2);
    int dp[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]); // 如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。
            }
        }
    }
    return dp[length1][length2]; // 这题dp的含义是前i和前j的最大公共序列（不一定非得以i,j结尾），所以dp数组的最后一个元素一定是最大的
}