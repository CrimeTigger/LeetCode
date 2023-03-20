bool lemonadeChange(int *bills, int billsSize)
{
    // �ֱ��¼��Ԫ��ʮԪ����������ʮԪ���ü�¼����Ϊ�����õ�20Ԫ���㣩
    int fiveCount = 0;
    int tenCount = 0;

    int i;
    for (i = 0; i < billsSize; ++i)
    {
        // ���������ÿλ�˿͵ĸ���
        switch (bills[i])
        {
        // ���һ��ֱ���տ���Ԫ
        case 5:
            fiveCount++;
            break;
        // ��������տ�ʮԪ
        case 10:
            // ��û����Ԫ���㣬����false
            if (fiveCount == 0)
                return false;
            // �տ�ʮԪ��������Ԫ
            fiveCount--;
            tenCount++;
            break;
        // ��������տ��ʮԪ
        case 20:
            // �����ԣ�������ʮԪ����Ԫ���㣨��ΪʮԪֻ������20��������Ҫ�����õ�����5Ԫ������ʮԪ�Ͷ�ʮԪ��
            if (fiveCount > 0 && tenCount > 0)
            {
                fiveCount--;
                tenCount--;
            }
            // ��û��ʮԪ��������������Ԫ����������Ԫ����
            else if (fiveCount >= 3)
                fiveCount -= 3;
            // �޷��ҿ�������false
            else
                return false;
            break;
        }
    }
    // ȫ�������ҿ�������true
    return true;
}