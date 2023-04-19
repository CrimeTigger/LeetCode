// dp[i][j]���ַ���s��[i, j]��Χ����Ļ��������еĳ���Ϊdp[i][j]��
int longestPalindromeSubseq(char *s)
{
    int length = strlen(s);
    int dp[length + 1][length + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < length; i++) // ��ʼ�� ��i��j��ͬ����ôdp[i][j]һ���ǵ���1�ģ�����һ���ַ��Ļ��������г��Ⱦ���1��
        dp[i][i] = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2; // ���s[i]��s[j]��ͬ����ôdp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]); // ���s[i]��s[j]����ͬ��˵��s[i]��s[j]��ͬʱ���� ����������[i,j]������������еĳ��ȣ���ô�ֱ����s[i]��s[j]������һ�����������Ļ��������С�
            }
        }
    }
    return dp[0][length - 1];
}