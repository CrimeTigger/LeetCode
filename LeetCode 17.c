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
    // 若当前下标等于digits数组长度
    if (index == strlen(digits))
    {
        // 复制digits数组，因为最后要多存储一个0，所以数组长度要+1
        char *tempString = (char *)malloc(sizeof(char) * strlen(digits) + 1);
        int j;
        for (j = 0; j < strlen(digits); j++)
        {
            tempString[j] = path[j];
        }
        // char数组最后要以0结尾
        tempString[strlen(digits)] = 0;
        result[resultTop++] = tempString;
        return;
    }
    // 将字符数字转换为真的数字
    int digit = digits[index] - '0';
    // 找到letterMap中对应的字符串
    char *letters = letterMap[digit];
    int i;
    for (i = 0; i < strlen(letters); i++)
    {
        path[pathTop++] = letters[i];
        // 递归，处理下一层数字
        backTracking(digits, index + 1);
        pathTop--;
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    // 初始化path和result
    path = (char *)malloc(sizeof(char) * strlen(digits));
    result = (char **)malloc(sizeof(char *) * 300);

    *returnSize = 0;
    // 若digits数组中元素个数为0，返回空集
    if (strlen(digits) == 0)
        return result;
    pathTop = resultTop = 0;
    backTracking(digits, 0);
    *returnSize = resultTop;

    return result;
}