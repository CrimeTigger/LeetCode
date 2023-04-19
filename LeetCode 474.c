// 本题中strs 数组里的元素就是物品，每个物品都是一个！

// 而m 和 n相当于是一个背包，两个维度的背包。
// dp[i][j]：最多有i个0和j个1的strs的最大子集的大小为dp[i][j]。

int findMaxForm(char **strs, int strsSize, int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));         // 初始为0
    for (int i = 0; i < strsSize; i++) // 遍历物品
    {
        int oneNum = 0;
        int zeroNum = 0;
        for (int j = 0; j < strlen(strs[i]); j++)
        {
            strs[i][j] == '0' ? zeroNum++ : oneNum++;
        }
        for (int x = m; x >= zeroNum; x--) // 遍历背包容量且从后向前遍历！
        {
            for (int y = n; y >= oneNum; y--)
            {
                dp[x][y] = fmax(dp[x][y], dp[x - zeroNum][y - oneNum] + 1);
            }
        }
    }
    return dp[m][n];
}