int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int m = obstacleGridSize;
    int n = obstacleGridColSize;
    int **dp = (int **)malloc(sizeof(int *) * m); // ��ʼ��dp����
    for (int i = 0; i < m; i++)
    {
        dp[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
    { // �������ϰ���֮��Ķ��߲��ˡ��˳�ѭ��
        if (obstacleGrid[i][0])
        {
            break;
        }
        dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
    {
        if (obstacleGrid[0][j])
        {
            break;
        }
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; i < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            { // ����ǰi,jλ�����ϰ�
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1]; // ����ǰi,jλ�����ϰ�
}