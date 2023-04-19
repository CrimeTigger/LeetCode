// dp[i][j]����i-1Ϊ��β��s�������г�����j-1Ϊ��β��t�ĸ���Ϊdp[i][j]��

//��s[i - 1] �� t[j - 1]���ʱ��dp[i][j]��������������ɡ�

// һ��������s[i - 1]��ƥ�䣬��ô����Ϊdp[i - 1][j - 1]��������Ҫ���ǵ�ǰs�Ӵ���t�Ӵ������һλ��ĸ������ֻ��Ҫ dp[i-1][j-1]��

// һ�����ǲ���s[i - 1]��ƥ�䣬����Ϊdp[i - 1][j]��
// ��s[i - 1] �� t[j - 1]�����ʱ��dp[i][j]ֻ��һ������ɣ�����s[i - 1]��ƥ�䣨����ģ����s��ɾ�����Ԫ�أ�������dp[i - 1][j]
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