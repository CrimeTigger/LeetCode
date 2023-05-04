int *path;
int pathTop;
int **ans;
int ansTop;
int *length;
// ����ǰpath�е����ݸ��Ƶ�ans��
void copy()
{
    int *tempPath = (int *)malloc(sizeof(int) * pathTop);
    memcpy(tempPath, path, pathTop * sizeof(int));
    length[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

// ����uset���Ƿ����ֵΪkey��Ԫ��
int find(int *uset, int usetSize, int key)
{
    int i;
    for (i = 0; i < usetSize; i++)
    {
        if (uset[i] == key)
            return 1;
    }
    return 0;
}

void backTracking(int *nums, int numsSize, int startIndex)
{
    // ��path��Ԫ�ش���1��ʱ����path������ans��
    if (pathTop > 1)
    {
        copy();
    }
    int *uset = (int *)malloc(sizeof(int) * numsSize);
    int usetTop = 0;
    int i;
    for (i = startIndex; i < numsSize; i++)
    {
        // ����ǰԪ��С��path�����һλԪ�� || ������ͬһ���ҵ�����ͬ��Ԫ�أ���continue
        if ((pathTop > 0 && nums[i] < path[pathTop - 1]) || find(uset, usetTop, nums[i]))
            continue;
        // ����ǰԪ�ط���uset
        uset[usetTop++] = nums[i];
        // ����ǰԪ�ط���path
        path[pathTop++] = nums[i];
        backTracking(nums, numsSize, i + 1);
        // ����
        pathTop--;
    }
}

int **findSubsequences(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // ���������ʼ��
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(sizeof(int *) * 33000);
    length = (int *)malloc(sizeof(int *) * 33000);
    pathTop = ansTop = 0;

    backTracking(nums, numsSize, 0);

    // ���������з���Ԫ�ظ������Լ�ÿ��һά����ĳ���
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}