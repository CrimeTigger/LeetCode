// Ϊ�������򾡿��ܵ��ص�����Ҫ�������������
// ��������ص��ˣ��ص��������ұ߽߱����Сֵ ֮ǰ������һ����Ҫһ��������

int cmp(const void *a, const void *b)
{
    return ((*((int **)a))[0] > (*((int **)b))[0]);
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    // ��points��������������
    qsort(points, pointsSize, sizeof(points[0]), cmp);

    int arrowNum = 1;
    int i = 1;
    for (i = 1; i < pointsSize; i++)
    {
        // ��ǰһ�������뵱ǰ�����ص���֤����Ҫ���Ӽ�������
        if (points[i][0] > points[i - 1][1])
            arrowNum++;
        else
            // ��ǰһ�������뵱ǰ�����ص����жϲ�������С��x_end
            points[i][1] = points[i][1] > points[i - 1][1] ? points[i - 1][1] : points[i][1];
    }
    return arrowNum;
}