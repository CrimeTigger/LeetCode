
int monotoneIncreasingDigits(int n)
{
    char temp[20];
    // itoa(n,temp,10);
    // ת�ַ���
    sprintf(temp, "%d", n);
    int size = strlen(temp);
    // flag������Ǹ�ֵ9�����￪ʼ
    // ����Ϊ���Ĭ��ֵ��Ϊ�˷�ֹ�ڶ���forѭ����flagû�б���ֵ�������ִ��
    int flag = size;
    for (int i = size - 1; i > 0; i--)
    {
        if (temp[i - 1] > temp[i])
        {
            temp[i - 1]--;
            flag = i;
        }
    }
    for (int i = flag; i < size; i++)
    {
        temp[i] = '9';
    }
    // ת����
    return atoi(temp);
    // return sscanf(temp, "%d", &n);
}