
// ���ת��Ϊ01���������ء�

// ����ӷ����ܺ�Ϊx����ô������Ӧ���ܺ;���sum - x��

// ��������Ҫ����� x - (sum - x) = target

// x = (target + sum) / 2

// ��ʱ�����ת��Ϊ��װ������Ϊx�ı������м��ַ�����
int findTargetSumWays(int *nums, int numsSize, int target)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (fabs(target) > sum) // ��ʱû�з���
        return 0;
    if ((target + sum) % 2) // ��ʱû�з���
        return 0;
    int bagSize = (target + sum) / 2;
    int *dp = malloc(sizeof(int) * (bagSize + 1));
    memset(dp, 0, sizeof(int) * (bagSize + 1));
    dp[0] = 1; // �������Ԫ�� 0 ǰ�����۷żӷ����Ǽ��������� 1 �ַ���
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = bagSize; j >= nums[i]; j--)
        {
            dp[j] += dp[j - nums[i]]; // ���е� dp[j - nums[i]] �ۼ�����
        }
    }
    return dp[bagSize];
}