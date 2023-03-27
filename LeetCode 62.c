
int uniquePaths(int m, int n)
{
    int **dp = (int **)malloc(sizeof(int *) * m); // dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����
    for (int i = 0; i < m; i++)
    {
        dp[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++) // ����dp[i][0]һ������1����Ϊ��(0, 0)��λ�õ�(i, 0)��·��ֻ��һ������ôdp[0][j]Ҳͬ��
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++) // ���Ǵ����Ϸ������Ƶ���������ô������һ��һ������Ϳ�����
    {
        for (int j = 1; j < n; j++)
        {

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // ��Ҫ��dp[i][j]��ֻ���������������Ƶ���������dp[i - 1][j] �� dp[i][j - 1]��
        }
    }
    return dp[m - 1][n - 1];
}