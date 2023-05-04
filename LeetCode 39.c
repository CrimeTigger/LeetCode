/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *path;
int pathTop;
int **ans;
int ansTop;
// 记录每一个和等于target的path数组长度
int *length;
void backtracking(int *candidates, int candidatesSize, int target, int sum, int startIndex)
{

    if (sum >= target)
    {
        // 若sum等于target，将当前的组合放入ans数组中
        if (sum == target)
        {
            int *tempPath = (int *)malloc(sizeof(int) * pathTop);
            int j;
            for (j = 0; j < pathTop; j++)
            {
                tempPath[j] = path[j];
            }
            ans[ansTop] = tempPath;
            length[ansTop++] = pathTop;
        }
        return;
    }

    int j;
    for (j = startIndex; j < candidatesSize; j++)
    {
        sum += candidates[j];
        path[pathTop++] = candidates[j];
        backtracking(candidates, candidatesSize, target, sum, j); // 同一个数字可以无限制重复被选取 j
        sum -= candidates[j];
        pathTop--;
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    // 初始化变量
    path = (int *)malloc(sizeof(int) * 50);
    ans = (int **)malloc(sizeof(int *) * 200);
    length = (int *)malloc(sizeof(int) * 200);
    ansTop = pathTop = 0;
    backtracking(candidates, candidatesSize, target, 0, 0);

    // 设置返回的数组大小
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}