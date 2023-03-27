int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int m = obstacleGridSize;
    int n = obstacleGridColSize;
    int **dp = (int **)malloc(sizeof(int *) * m); // 初始化dp数组
    for (int i = 0; i < m; i++)
    {
        dp[i] = malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
    { // 若碰到障碍，之后的都走不了。退出循环
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
            { // 若当前i,j位置有障碍
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1]; // 若当前i,j位置有障碍
}