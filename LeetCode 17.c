char *path;
int pathTop;
char **result;
int resultTop;
char *letterMap[10] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz", // 9
};
void backTracking(char *digits, int index)
{
    // ����ǰ�±����digits���鳤��
    if (index == strlen(digits))
    {
        // ����digits���飬��Ϊ���Ҫ��洢һ��0���������鳤��Ҫ+1
        char *tempString = (char *)malloc(sizeof(char) * strlen(digits) + 1);
        int j;
        for (j = 0; j < strlen(digits); j++)
        {
            tempString[j] = path[j];
        }
        // char�������Ҫ��0��β
        tempString[strlen(digits)] = 0;
        result[resultTop++] = tempString;
        return;
    }
    // ���ַ�����ת��Ϊ�������
    int digit = digits[index] - '0';
    // �ҵ�letterMap�ж�Ӧ���ַ���
    char *letters = letterMap[digit];
    int i;
    for (i = 0; i < strlen(letters); i++)
    {
        path[pathTop++] = letters[i];
        // �ݹ飬������һ������
        backTracking(digits, index + 1);
        pathTop--;
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    // ��ʼ��path��result
    path = (char *)malloc(sizeof(char) * strlen(digits));
    result = (char **)malloc(sizeof(char *) * 300);

    *returnSize = 0;
    // ��digits������Ԫ�ظ���Ϊ0�����ؿռ�
    if (strlen(digits) == 0)
        return result;
    pathTop = resultTop = 0;
    backTracking(digits, 0);
    *returnSize = resultTop;

    return result;
}