int combinationSum4(int *nums, int numsSize, int target)
{
    int dp[target + 1]; // dp[i]: �ճ�Ŀ��������Ϊi�����и���Ϊdp[i]
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i <= target; i++) // target��������������ѭ������nums����Ʒ��������ѭ������ѭ����ǰ���������
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
            {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}