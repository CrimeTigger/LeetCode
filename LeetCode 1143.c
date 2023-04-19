// ����Ͷ�̬�滮��718. ��ظ������������������ﲻҪ�����������ˣ���Ҫ�����˳�򣬼���"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С�
// dp[i][j]������Ϊ[0, i - 1]���ַ���text1�볤��Ϊ[0, j - 1]���ַ���text2�������������Ϊdp[i][j]

int longestCommonSubsequence(char *text1, char *text2)
{
    int length1 = strlen(text1);
    int length2 = strlen(text2);
    int dp[length1 + 1][length2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= length1; i++)
    {
        for (int j = 1; j <= length2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]); // ���text1[i - 1] �� text2[j - 1]����ͬ���ǾͿ���text1[0, i - 2]��text2[0, j - 1]������������� �� text1[0, i - 1]��text2[0, j - 2]������������У�ȡ���ġ�
            }
        }
    }
    return dp[length1][length2]; // ����dp�ĺ�����ǰi��ǰj����󹫹����У���һ���ǵ���i,j��β��������dp��������һ��Ԫ��һ��������
}