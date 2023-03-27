int minCostClimbingStairs(int* cost, int costSize){
    int *dp=malloc(sizeof(int) * (costSize+1) );
    dp[0]=dp[1]=0;//初始化 dp[0] = 0，dp[1] = 0;
    for(int i=2;i<=costSize;i++){//
        dp[i]=fmin(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);//确定递推公式
    }
    return dp[costSize];
}