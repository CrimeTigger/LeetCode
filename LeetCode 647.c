// 布尔类型的dp[i][j]：表示区间范围[i,j]

// 当s[i]与s[j]相等时，这就复杂一些了，有如下三种情况

// 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
// 情况二：下标i 与 j相差为1，例如aa，也是回文子串
// 情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串就看aba是不是回文就可以了，
// 那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true。

// 遍历顺序 情况三是根据dp[i + 1][j - 1]是否为true，在对dp[i][j]进行赋值true的
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