

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int *dailyTemperatures(int *temperatures, int temperaturesSize, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * temperaturesSize);
    int stack[temperaturesSize + 1], top = 0;
    memset(res, 0, temperaturesSize * sizeof(int)); //给res赋值0
    *returnSize = temperaturesSize;
    for (int i = 0; i < temperaturesSize; i++)
    {
        while (top > 0 && temperatures[i] > temperatures[stack[top - 1]])

        {
            res[stack[top - 1]] = i - stack[top - 1];
            top--; /* code */
        }
        stack[top++] = i;
    }
    return res;
}
