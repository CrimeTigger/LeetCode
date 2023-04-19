//dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。


//dp[i][0]：word2为空字符串，以i-1为结尾的字符串word1要删除多少个元素，才能和word2相同呢，很明显dp[i][0] = i。

// dp[0][j]的话同理
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
                dp[i][j] = fmin(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
    }
    return dp[length1][length2];
}

// 方法二
// ，只要求出两个字符串的最长公共子序列长度即可，那么除了最长公共子序列之外的字符都是必须删除的，最后用两个字符串的总长度减去两个最长公共子序列的长度就是删除的最少步数。
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return word1.size() + word2.size() - dp[word1.size()][word2.size()] * 2;
    }
};
