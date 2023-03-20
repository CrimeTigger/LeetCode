
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *partitionLabels(char *s, int *returnSize)
{
    int strSize = strlen(s);              // i为字符，hash[i]为字符出现的最后位置
    int *hash = malloc(sizeof(int) * 27); // 统计每一个字符最后出现的位置
    int *result = (int *)malloc(sizeof(int) * 500);
    int resTop = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < strSize; i++)
    {
        hash[s[i] - 'a'] = i;
    }
    for (int i = 0; i < strSize; i++)
    {
        right = fmax(right, hash[s[i] - 'a']); // 找到字符出现的最远边界
        if (i == right)
        {
            result[resTop++] = right - left + 1;
            left = i + 1;
        }
    }
    *returnSize = resTop;
    return result;
}