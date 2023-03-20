// 贪心
int wiggleMaxLength(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int length = 1;
    int preDiff, curDiff;
    preDiff = curDiff = 0;
    for (int i = 0; i < numsSize - 1; ++i)
    {
        // 计算当前i元素与i+1元素差值
        curDiff = nums[i + 1] - nums[i];

        // 若preDiff与curDiff符号不符，则子序列长度+1。更新preDiff的符号
        // 若preDiff与curDiff符号一致，当前i元素为连续升序/连续降序子序列的中间元素。不被记录入长度
        // 注：当preDiff为0时，curDiff为正或为负都属于符号不同
        if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
        {
            preDiff = curDiff;
            length++;
        }
    }

    return length;
}

// 动态规划
int max(int left, int right)
{
    return left > right ? left : right;
}
int wiggleMaxLength(int *nums, int numsSize)
{
    if (numsSize <= 1)
    {
        return numsSize;
    }
    // 0   i 作为波峰的最大长度
    // 1   i 作为波谷的最大长度
    int dp[numsSize][2];
    for (int i = 0; i < numsSize; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
        for (int j = 0; j < i; j++)
        {
            // nums[i] 为山谷
            if (nums[j] > nums[i])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            // nums[i] 为山峰
            if (nums[j] < nums[i])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
    }
    return max(dp[numsSize - 1][0], dp[numsSize - 1][1]);
}