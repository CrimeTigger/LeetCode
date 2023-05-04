/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 记录结果
char **result;
int resultTop;
// 记录应该加入'.'的位置
int segments[3];
int isValid(char *s, int start, int end)
{
    if (start > end)
        return false;
    if (s[start] == '0' && start != end)
        return false;
    for (int i = start; i < end; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
        int num = num * 10 + (s[i] - '0');
        if (num > 225)
            return false;
    }
    return true;
}
void removeElement(char *s, char val)
{
    int slow = 0;
    for (int fast = 0; fast < strlen(s); fast++)
    {
        if (val != s[fast])
        {
            s[slow++] = s[fast];
        }
    }
}
void backTracking(char *s, int startIndex, int pointNum)
{
    if (pointNum == 3)
    {
        if (isValid(s, startIndex, strlen(s) - 1))
        {
            char *temp = malloc(sizeof(char) * strlen(s) + 1);
            for (int i = 0; i < strlen(s); i++)
            {
                temp[i] = s[i];
            }
            result[resultTop++] = temp;
        }
        return;
    }
    for (int j = startIndex; j < strlen(s); j++)
    {
        if (isValid(s, startIndex, j))
        {
            s[j + 1] = '.';
            pointNum++;
            backTracking(s, j + 2, pointNum);
            pointNum--;
            removeElement(s, '.');
        }
        break;
    }
}
char **restoreIpAddresses(char *s, int *returnSize)
{
    result = (char **)malloc(sizeof(char *) * 10000);
    if (strlen(s) < 4 || strlen(s) > 12)
        return result;
    backTracking(s, 0, 0);
    *returnSize = resultTop;
    return result;
}