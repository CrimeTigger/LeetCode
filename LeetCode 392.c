// dp[i][j] ��ʾ���±�i-1Ϊ��β���ַ���s�������±�j-1Ϊ��β���ַ���t����ͬ�����еĳ���Ϊdp[i][j]��

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
                dp[i][j] = dp[i][j - 1]; // if (s[i - 1] != t[j - 1])����ʱ�൱��tҪɾ��Ԫ�أ�t����ѵ�ǰԪ��t[j - 1]ɾ������ôdp[i][j] ����ֵ���� ��s[i - 1]�� t[j - 2]�ıȽϽ���ˣ�����dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[length1][length2] == length1; // dp[i][j]��ʾ���±�i-1Ϊ��β���ַ���s�����±�j-1Ϊ��β���ַ���t ��ͬ�����еĳ��ȣ��������dp[s.size()][t.size()] �� �ַ���s�ĳ�����ͬ˵����s��t�����ͬ�����о���s����ôs ���� t �������С�
}