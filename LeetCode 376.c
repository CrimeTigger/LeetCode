// ̰��
int wiggleMaxLength(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int length = 1;
    int preDiff, curDiff;
    preDiff = curDiff = 0;
    for (int i = 0; i < numsSize - 1; ++i)
    {
        // ���㵱ǰiԪ����i+1Ԫ�ز�ֵ
        curDiff = nums[i + 1] - nums[i];

        // ��preDiff��curDiff���Ų������������г���+1������preDiff�ķ���
        // ��preDiff��curDiff����һ�£���ǰiԪ��Ϊ��������/�������������е��м�Ԫ�ء�������¼�볤��
        // ע����preDiffΪ0ʱ��curDiffΪ����Ϊ�������ڷ��Ų�ͬ
        if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
        {
            preDiff = curDiff;
            length++;
        }
    }

    return length;
}

// ��̬�滮
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
    // 0   i ��Ϊ�������󳤶�
    // 1   i ��Ϊ���ȵ���󳤶�
    int dp[numsSize][2];
    for (int i = 0; i < numsSize; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
        for (int j = 0; j < i; j++)
        {
            // nums[i] Ϊɽ��
            if (nums[j] > nums[i])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            // nums[i] Ϊɽ��
            if (nums[j] < nums[i])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
    }
    return max(dp[numsSize - 1][0], dp[numsSize - 1][1]);
}