int *path;
int pathTop;
int **ans;
int ansTop;
// ��¼��ά������ÿ��һά����ĳ���
int *length;
// ����ǰpath���鸴�Ƶ�ans��
void copy()
{
    int *tempPath = (int *)malloc(sizeof(int) * pathTop);
    int i;
    for (i = 0; i < pathTop; i++)
    {
        tempPath[i] = path[i];
    }
    ans = (int **)realloc(ans, sizeof(int *) * (ansTop + 1));
    length[ansTop] = pathTop;
    ans[ansTop++] = tempPath;
}

void backTracking(int *nums, int numsSize, int startIndex)
{
    // �ռ��Ӽ���Ҫ������ֹ��ӵ����棬�����©���Լ�
    copy();
    // ʣ�༯��Ϊ�յ�ʱ�򣬾���Ҷ�ӽڵ㡣
    if (startIndex >= numsSize)
    {
        return;
    }
    int j;
    for (j = startIndex; j < numsSize; j++)
    {
        // ����ǰ�±����ַ���path��
        path[pathTop++] = nums[j];
        backTracking(nums, numsSize, j + 1);
        // ����
        pathTop--;
    }
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // ��ʼ����������
    path = (int *)malloc(sizeof(int) * numsSize);
    ans = (int **)malloc(0);
    length = (int *)malloc(sizeof(int) * 1500);
    ansTop = pathTop = 0;
    // �������
    backTracking(nums, numsSize, 0);
    // ���ö�ά������Ԫ�ظ���
    *returnSize = ansTop;
    // ���ö�ά������ÿ��һά����ĳ���
    *returnColumnSizes = (int *)malloc(sizeof(int) * ansTop);
    int i;
    for (i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}