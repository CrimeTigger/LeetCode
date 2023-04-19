// �������͵�dp[i][j]����ʾ���䷶Χ[i,j]

// ��s[i]��s[j]���ʱ����͸���һЩ�ˣ��������������

// ���һ���±�i �� j��ͬ��ͬһ���ַ�����a����Ȼ�ǻ����Ӵ�
// ��������±�i �� j���Ϊ1������aa��Ҳ�ǻ����Ӵ�
// ��������±꣺i �� j������1��ʱ������cabac����ʱs[i]��s[j]�Ѿ���ͬ�ˣ����ǿ�i��j�����ǲ��ǻ����Ӵ��Ϳ�aba�ǲ��ǻ��ľͿ����ˣ�
// ��ôaba��������� i+1 �� j-1���䣬��������ǲ��ǻ��ľͿ�dp[i + 1][j - 1]�Ƿ�Ϊtrue��

// ����˳�� ������Ǹ���dp[i + 1][j - 1]�Ƿ�Ϊtrue���ڶ�dp[i][j]���и�ֵtrue��
int countSubstrings(char *s)
{
    int length = strlen(s);
    bool dp[length][length];
    memset(dp, false, sizeof(dp));
    int result = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i; j < length; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}