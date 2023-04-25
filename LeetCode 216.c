

int **res;
int *paths;
int resTop;
int pathTop;
void backtracking(int k, int n, int sum, int startIndex)
{
    if (sum > n) // ��ѡԪ���ܺ�����Ѿ�����n��ͼ����ֵΪ4���ˣ���ô���������û�������ˣ�ֱ�Ӽ���
        return;
    if (pathTop == k)
    {
        if (sum == n)
        {
            int *temp = malloc(sizeof(int) * (k + 1));
            for (int i = 0; i < k; i++)
            {
                temp[i] = paths[i];
            }
            res[resTop++] = temp;
        }
        return;
    }
    for (int i = startIndex; i <= 9 - (k - pathTop) + 1; i++) // ��֦
    {
        sum += i;
        paths[pathTop++] = i;
        backtracking(k, n, sum, i + 1);
        sum -= i;
        pathTop--;
    }
}
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
    // path����洢���������Ľ��
    paths = (int *)malloc(sizeof(int) * k);
    // ans��ά����洢���������Ľ������ļ��ϡ��������㹻�󣬱��⼫�������
    res = (int **)malloc(sizeof(int *) * 10000);
    pathTop = resTop = 0;

    // �����㷨
    backtracking(k, n, 0, 1);
    // ���ķ��ش�СΪres�����С
    *returnSize = resTop;
    // returnColumnSizes����洢ans��ά�����Ӧ�±���һά����ĳ��ȣ���Ϊk��
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    for (i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = k;
    }
    // ����ans��ά����
    return res;
}