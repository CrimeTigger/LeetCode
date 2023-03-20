
// ��ô�ֲ����ţ���ǰ�ۼ�rest[i]�ĺ�curSumһ��С��0����ʼλ������Ҫ��i+1����Ϊ��i֮ǰ��ʼһ�����С�ȫ�����ţ��ҵ�������һȦ����ʼλ�á�
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    int curSum = 0;
    int totalSum = 0;
    int start = 0;

    int i;
    for (i = 0; i < gasSize; ++i)
    {
        // ��ǰiվ�м�������������Ĳ�
        int diff = gas[i] - cost[i];

        curSum += diff;
        totalSum += diff;

        // ��0��i�ļ�������Ϊ������ʼλ��ӦΪi+1
        if (curSum < 0)
        {
            curSum = 0;
            // ��i + 1 == gasSizeʱ��totalSum < 0����ʱiΪgasSize - 1)���ͳ������ܷ���ԭ��
            start = i + 1;
        }
    }

    // ���ܺ�С��0�����ͳ�������ζ��޷�����ԭ�㡣����-1
    if (totalSum < 0)
        return -1;

    return start;
}