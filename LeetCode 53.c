// ̰��
int maxSubArray(int *nums, int numsSize)
{
    int maxVal = INT_MIN;
    int subArrSum = 0;

    int i;
    for (i = 0; i < numsSize; ++i)
    {
        subArrSum += nums[i];
        // ����ǰ�ֲ��ʹ���֮ǰ����������Խ�����и���
        maxVal = subArrSum > maxVal ? subArrSum : maxVal;
        // ����ǰ�ֲ���Ϊ�����Խ�����档���nums[i+1]��ʼӦ���¼��㡣
        subArrSum = subArrSum < 0 ? 0 : subArrSum;
    }

    return maxVal;
}

// ��̬�滮
/**
 * ����˼·����̬�滮��
 * 1. dp���飺dp[i]��ʾ��0��i����������������к͵�ֵ
 * 2. ���ƹ�ʽ��dp[i] = max(dp[i-1] + nums[i], nums[i])
        ��dp[i-1]<0������������档dp[i]��Ϊnums[i]��
 * 3. dp�����ʼ����dp[0]������������Ϊnums[0]
 * 4. �Ƶ�˳�򣺴�ǰ�������
 */

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(int *nums, int numsSize)
{
    int dp[numsSize];
    // dp[0]����������Ϊnums[0]
    dp[0] = nums[0];
    // ��numsSizeΪ1��Ӧֱ�ӷ���nums[0]
    int subArrSum = nums[0];

    int i;
    for (i = 1; i < numsSize; ++i)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);

        // ��dp[i]����֮ǰ��¼�����ֵ�����и���
        if (dp[i] > subArrSum)
            subArrSum = dp[i];
    }

    return subArrSum;
}