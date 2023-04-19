
// ���dp[target]��������Ϊtarget�ı������ܱ������������

// ��ô�ֳ�����ʯͷ��һ��ʯͷ����������dp[target]����һ�Ѿ���sum - dp[target]��

// �ڼ���target��ʱ��target = sum / 2 ��Ϊ������ȡ��������sum - dp[target] һ���Ǵ��ڵ���dp[target]�ġ�

// ��ô��ײ֮��ʣ�µ���Сʯͷ�������� (sum - dp[target]) - dp[target]��
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