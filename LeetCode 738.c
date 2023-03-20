
int monotoneIncreasingDigits(int n)
{
    char temp[20];
    // itoa(n,temp,10);
    // 转字符串
    sprintf(temp, "%d", n);
    int size = strlen(temp);
    // flag用来标记赋值9从哪里开始
    // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
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
    // 转数字
    return atoi(temp);
    // return sscanf(temp, "%d", &n);
}