
int countSubstrings(char *s)
{
    int length = strlen(s);
    bool dp[length][length];
    memset(dp, false, sizeof(dp));
    int result = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = i; j < length; j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}