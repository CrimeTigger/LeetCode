
// 如何转化为01背包问题呢。

// 假设加法的总和为x，那么减法对应的总和就是sum - x。

// 所以我们要求的是 x - (sum - x) = target

// x = (target + sum) / 2

// 此时问题就转化为，装满容量为x的背包，有几种方法。
int findTargetSumWays(int *nums, int numsSize, int target)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (fabs(target) > sum) // 此时没有方案
        return 0;
    if ((target + sum) % 2) // 此时没有方案
        return 0;
    int bagSize = (target + sum) / 2;
    int *dp = malloc(sizeof(int) * (bagSize + 1));
    memset(dp, 0, sizeof(int) * (bagSize + 1));
    dp[0] = 1; // 数组里的元素 0 前面无论放加法还是减法，都是 1 种方法
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = bagSize; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]]; // 所有的 dp[j - nums[i]] 累加起来
        }
    }
    return dp[bagSize];
}