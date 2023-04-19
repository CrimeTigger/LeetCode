// ��άdp��
/**
1. dp���麬�壺dp[i][j]Ϊ��������Ϊjʱ����[0-i]Ԫ�غ����ֵ
2. ���ƹ�ʽ��dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i])
3. ��ʼ����dp[i][0]��ʼ��Ϊ0����Ϊ��������Ϊ0ʱ�������ܷ���Ԫ�ء�dp[0][j] = nums[0]����j >= nums[0] && j < targetʱ
4. ����˳���ȱ�����Ʒ���ٱ�������
*/
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int getSum(int *nums, int numsSize)
{
    int sum = 0;

    int i;
    for (i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    return sum;
}

bool canPartition(int *nums, int numsSize)
{
    // ���Ԫ���ܺ�
    int sum = getSum(nums, numsSize);
    // ��Ԫ���ܺ�Ϊ�������򲻿��ܵõ���������ȵ�������
    if (sum % 2)
        return false;

    // ��������ĺ͵���target����nums���Ա��ָ�
    int target = sum / 2;
    // ��ʼ��dp����
    int dp[numsSize][target + 1];
    // dp[j][0]��Ӧ������Ϊ0����Ϊ����������Ϊ0ʱ�����ɷ���Ԫ��
    memset(dp, 0, sizeof(int) * numsSize * (target + 1));

    int i, j;
    // ����������j����nums[0]ʱ��������dp[0][j]�з���Ԫ��nums[0]
    for (j = nums[0]; j <= target; ++j)
    {
        dp[0][j] = nums[0];
    }

    for (i = 1; i < numsSize; ++i)
    {
        for (j = 1; j <= target; ++j)
        {
            // ����ǰ��������jС��nums[i]������ֵ����ֻ����0��i-1��Ʒʱ��ֵ
            if (j < nums[i])
                dp[i][j] = dp[i - 1][j];
            // ���򣬱������������ڱ����з���num[i]/������nums[i]�Ľϴ�ֵ
            else
                dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
        }
    }
    // �жϱ�������Ϊtarget���ҿ��ǵ�������Ʒʱ�������Ԫ�غ��Ƿ����target
    return dp[numsSize - 1][target] == target;
}

// �������飺
/**
1. dp���麬�壺dp[j]Ϊ��������Ϊjʱ�����пɷ���Ԫ�ص����ֵ
2. ���ƹ�ʽ��dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
3. ��ʼ��������ʼ��Ϊ0����
4. ����˳���ȱ�����Ʒ���ٺ����������
*/
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int getSum(int *nums, int numsSize)
{
    int sum = 0;

    int i;
    for (i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    return sum;
}

bool canPartition(int *nums, int numsSize)
{
    // ���Ԫ���ܺ�
    int sum = getSum(nums, numsSize);
    // ��Ԫ���ܺ�Ϊ�������򲻿��ܵõ���������ȵ�������
    if (sum % 2)
        return false;
    // ��������
    int target = sum / 2;

    // ��ʼ��dp���飬Ԫ�ؾ�Ϊ0
    int dp[target + 1];
    memset(dp, 0, sizeof(int) * (target + 1));

    int i, j;
    // �ȱ�����Ʒ�����������
    for (i = 0; i < numsSize; ++i)
    {
        for (j = target; j >= nums[i]; --j)
        {
            dp[j] = MAX(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    // �鿴��������Ϊtargetʱ��Ԫ���ܺ��Ƿ����target
    return dp[target] == target;
}