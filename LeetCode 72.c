// dp[i][j] ��ʾ���±�i-1Ϊ��β���ַ���word1�������±�j-1Ϊ��β���ַ���word2������༭����Ϊdp[i][j]��

// ����һ��word1ɾ��һ��Ԫ�� �� dp[i][j] = dp[i - 1][j] + 1;
// ��������word2ɾ��һ��Ԫ�� �� dp[i][j] = dp[i][j - 1] + 1;  word2���һ��Ԫ�أ��൱��word1ɾ��һ��Ԫ�أ�����һ��
// ���������滻Ԫ��  dp[i][j] = dp[i - 1][j - 1] + 1;
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