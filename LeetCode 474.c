// ������strs �������Ԫ�ؾ�����Ʒ��ÿ����Ʒ����һ����

// ��m �� n�൱����һ������������ά�ȵı�����
// dp[i][j]�������i��0��j��1��strs������Ӽ��Ĵ�СΪdp[i][j]��

int findMaxForm(char **strs, int strsSize, int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));         // ��ʼΪ0
    for (int i = 0; i < strsSize; i++) // ������Ʒ
    {
        int oneNum = 0;
        int zeroNum = 0;
        for (int j = 0; j < strlen(strs[i]); j++)
        {
            strs[i][j] == '0' ? zeroNum++ : oneNum++;
        }
        for (int x = m; x >= zeroNum; x--) // �������������ҴӺ���ǰ������
        {
            for (int y = n; y >= oneNum; y--)
            {
                dp[x][y] = fmax(dp[x][y], dp[x - zeroNum][y - oneNum] + 1);
            }
        }
    }
    return dp[m][n];
}