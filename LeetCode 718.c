//dp[i][j] �����±�i - 1Ϊ��β��A�������±�j - 1Ϊ��β��B����ظ������鳤��Ϊdp[i][j]

int findLength(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int dp[nums1Size + 1][nums2Size + 1];
    memset(dp, 0, sizeof(dp));
    int result = 0;
    int j;
    for (int i = 1; i <= nums1Size; i++)
    {
        for (int j = 1; j <= nums2Size; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            result = result > dp[i][j] ? result : dp[i][j];
        }
    }
    return result;
}