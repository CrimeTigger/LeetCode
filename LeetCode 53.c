// 贪心
int maxSubArray(int *nums, int numsSize)
{
    int maxVal = INT_MIN;
    int subArrSum = 0;

    int i;
    for (i = 0; i < numsSize; ++i)
    {
        subArrSum += nums[i];
        // 若当前局部和大于之前的最大结果，对结果进行更新
        maxVal = subArrSum > maxVal ? subArrSum : maxVal;
        // 若当前局部和为负，对结果无益。则从nums[i+1]开始应重新计算。
        subArrSum = subArrSum < 0 ? 0 : subArrSum;
    }

    return maxVal;
}

// 动态规划
/**
 * 解题思路：动态规划：
 * 1. dp数组：dp[i]表示从0到i的子序列中最大序列和的值
 * 2. 递推公式：dp[i] = max(dp[i-1] + nums[i], nums[i])
        若dp[i-1]<0，对最后结果无益。dp[i]则为nums[i]。
 * 3. dp数组初始化：dp[0]的最大子数组和为nums[0]
 * 4. 推导顺序：从前往后遍历
 */

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(int *nums, int numsSize)
{
    int dp[numsSize];
    // dp[0]最大子数组和为nums[0]
    dp[0] = nums[0];
    // 若numsSize为1，应直接返回nums[0]
    int subArrSum = nums[0];

    int i;
    for (i = 1; i < numsSize; ++i)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);

        // 若dp[i]大于之前记录的最大值，进行更新
        if (dp[i] > subArrSum)
            subArrSum = dp[i];
    }

    return subArrSum;
}