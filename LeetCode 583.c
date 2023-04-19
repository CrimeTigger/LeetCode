//dp[i][j]����i-1Ϊ��β���ַ���word1������j-1λ��β���ַ���word2����Ҫ�ﵽ��ȣ�����Ҫɾ��Ԫ�ص����ٴ�����


//dp[i][0]��word2Ϊ���ַ�������i-1Ϊ��β���ַ���word1Ҫɾ�����ٸ�Ԫ�أ����ܺ�word2��ͬ�أ�������dp[i][0] = i��

// dp[0][j]�Ļ�ͬ��
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

// ������
// ��ֻҪ��������ַ���������������г��ȼ��ɣ���ô���������������֮����ַ����Ǳ���ɾ���ģ�����������ַ������ܳ��ȼ�ȥ��������������еĳ��Ⱦ���ɾ�������ٲ�����
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
