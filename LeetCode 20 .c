char pairs(char a)
{
    if (a == ')')
        return '(';
    if (a == ']')
        return '[';
    if (a == '}')
        return '{';
    return 0;
}

bool isValid(char *s)
{
    int len = strlen(s);
    if (len % 2 != 0)
    {
        return false;
    }
    int ops[len + 1], top = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = pairs(s[i]);
        if (ch)
        {
            if (top == 0 || ch != ops[top - 1])
            {
                return false;
            }
            top--;
        }
        else
        {
            ops[top++] = s[i];
        }
    }
    return top == 0;
}