/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdio.h>
int *path;
int pathTop;
int **ans;
int ansTop;
// 记录每一个和等于target的path数组长度
int *length;
int cmp(const void *a1, const void *a2)
{
    return *((int *)a1) - *((int *)a2);
}

void backtracking(int *candidates, int candidatesSize, int target, int sum, int *used, int startIndex)
{
    if (sum >= target)
    {
        if (sum == target)
        {
            int *temp = malloc(sizeof(int) * (pathTop + 1));
            for (int i = 0; i < pathTop; i++)
            {
                temp[i] = path[i];
            }
            length[ansTop] = pathTop;
            ans[ansTop++] = temp;
        }
        return;
    }
    for (int i = startIndex; i < candidatesSize; i++)
    {
        if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false)////对同一树层使用过的元素进行跳过
        {
            continue;
        }
        sum += candidates[i];
        path[pathTop++] = candidates[i];
        used[i] = true;
        backtracking(candidates, candidatesSize, target, sum, used, i + 1);
        sum -= candidates[i];
        pathTop--;
        used[i] = false;
    }
}
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    // bool *used=malloc(sizeof(bool)*candidatesSize);
    int *used[candidatesSize];
    memset(used, false, sizeof(used));
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    path = (int *)malloc(sizeof(int) * 50);
    ans = (int **)malloc(sizeof(int *) * 100);
    length = (int *)malloc(sizeof(int) * 100);
    pathTop = ansTop = 0;
    int sum = 0;
    backtracking(candidates, candidatesSize, target, sum, used, 0);
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}