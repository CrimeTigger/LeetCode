/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *path;
int pathTop;
int **ans;
int ansTop;
// ��¼ÿһ���͵���target��path���鳤��
int *length;
void backtracking(int *candidates, int candidatesSize, int target, int sum, int startIndex)
{

    if (sum >= target)
    {
        // ��sum����target������ǰ����Ϸ���ans������
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
        backtracking(candidates, candidatesSize, target, sum, j); // ͬһ�����ֿ����������ظ���ѡȡ j
        sum -= candidates[j];
        pathTop--;
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    // ��ʼ������
    path = (int *)malloc(sizeof(int) * 50);
    ans = (int **)malloc(sizeof(int *) * 200);
    length = (int *)malloc(sizeof(int) * 200);
    ansTop = pathTop = 0;
    backtracking(candidates, candidatesSize, target, 0, 0);

    // ���÷��ص������С
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}