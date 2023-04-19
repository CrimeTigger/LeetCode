//dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]

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