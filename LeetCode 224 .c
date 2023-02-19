int calculate(char *s)
{
    int n = strlen(s);
    int ops[n + 1], top = 0;
    int sign = 1;
    ops[top++] = sign;
    int res = 0;
    int i = 0;
    while (i < n)
    {
        if (s[i] == ' ')
        {
            i++;
        }
        if (s[i] == '+')
        {
            sign = ops[top - 1];
            i++;
        }
        if (s[i] == '-')
        {
            sign = -ops[top - 1];
            i++;
        }
        if (s[i] == '(')
        {
            ops[top++] = sign;
            i++;
        }
        if (s[i] == ')')
        {
            top--;
            i++;
        }
        else
        {
            long num = 0;
            while (i < n && s[i] > '0' && s[i] < '9')
            {
                num = num * 10 + s[i] - '0';
                i++;
            }
            res += sign * num;
        }
    }
    return res;
}