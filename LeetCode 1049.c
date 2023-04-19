
// 最后dp[target]里是容量为target的背包所能背的最大重量。

// 那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。

// 在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。

// 那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。
int lastStoneWeightII(int *stones, int stonesSize)
{
    int target;
    int i;
    int sum;
    for (i = 0; i < stonesSize; i++)
    {
        sum += stones[i];
    }
    target = sum / 2;
    int *dp = malloc(sizeof(int) * (target + 1));
    memset(dp, 0, sizeof(int) * (target + 1));
    for (i = 0; i < stonesSize; i++)
    {
        for (int j = target; j >= stones[i]; j--)
        {
            dp[j] = fmax(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    int result = sum - dp[target] - dp[target];
    return result;
}