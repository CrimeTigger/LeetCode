// �ֲ����ţ��þ���ֵ��ĸ�����Ϊ��������ǰ��ֵ�ﵽ����������ţ���������ʹﵽ���

int cmp(int *a, int *b)
{
    return fabs(*b) - fabs(*a);
}

int largestSumAfterKNegations(int *nums, int numsSize, int k)
{
    int result = 0;
    // �����鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
    qsort(nums, numsSize, sizeof(int), cmp);
    // ��ǰ���������������������Ϊ������ͬʱK--
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 && k > 0)
        {
            nums[i] *= -1;
            k--;
        }
    }
    // ���K������0����ô����ת����ֵ��С��Ԫ�أ���K����
    if (k % 2 == 1)
        nums[numsSize - 1] *= -1;
    // ���
    for (int j = 0; j < numsSize; j++)
    {
        result += nums[j];
    }
    return result;
}