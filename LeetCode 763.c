
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *partitionLabels(char *s, int *returnSize)
{
    int strSize = strlen(s);              // iΪ�ַ���hash[i]Ϊ�ַ����ֵ����λ��
    int *hash = malloc(sizeof(int) * 27); // ͳ��ÿһ���ַ������ֵ�λ��
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
        right = fmax(right, hash[s[i] - 'a']); // �ҵ��ַ����ֵ���Զ�߽�
        if (i == right)
        {
            result[resTop++] = right - left + 1;
            left = i + 1;
        }
    }
    *returnSize = resTop;
    return result;
}