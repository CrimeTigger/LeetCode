int *path;
int pathTop;
int **ans;
int ansTop;
// �����Ŷ�ά������ÿ������ĳ���
int *lengths;
// ����cmp����
int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

// ���ƺ���������ǰpath�е�Ԫ�ظ��Ƶ�ans�С�ͬʱ��¼path����
void copy()
{
    int *tempPath = (int *)malloc(sizeof(int) * pathTop);
    int i;
    for (i = 0; i < pathTop; i++)
    {
        tempPath[i] = path[i];
    }
    ans = (int **)realloc(ans, sizeof(int *) * (ansTop + 1));
    lengths[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

void backTracking(int *nums, int numsSize, int startIndex, int *used)
{
    // ���Ƚ���ǰpath����
    copy();
    // ��startIndex�����������һλԪ�ص�λ�ã�����
    if (startIndex >= numsSize)
        return;

    int i;
    for (i = startIndex; i < numsSize; i++)
    {
        // ��ͬһ����ʹ�ù���Ԫ�ؽ�������
        if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            continue;
        path[pathTop++] = nums[i];
        used[i] = true;
        backTracking(nums, numsSize, i + 1, used);
        used[i] = false;
        pathTop--;
    }
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // ������������
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(0);
    lengths = (int *)malloc(sizeof(int) * 1500);
    int *used = (int *)malloc(sizeof(int) * numsSize);
    pathTop = ansTop = 0;

    // �������ز�����Ч
    qsort(nums, numsSize, sizeof(int), cmp);
    backTracking(nums, numsSize, 0, used);

    // ����һά����Ͷ�ά����ķ��ش�С
    *returnSize = ansTop;
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = lengths[i];
    }
    return ans;
}