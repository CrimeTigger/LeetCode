// 为了让气球尽可能的重叠，需要对数组进行排序。
// 如果气球重叠了，重叠气球中右边边界的最小值 之前的区间一定需要一个弓箭。

int cmp(const void *a, const void *b)
{
    return ((*((int **)a))[0] > (*((int **)b))[0]);
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
    // 将points数组作升序排序
    qsort(points, pointsSize, sizeof(points[0]), cmp);

    int arrowNum = 1;
    int i = 1;
    for (i = 1; i < pointsSize; i++)
    {
        // 若前一个气球与当前气球不重叠，证明需要增加箭的数量
        if (points[i][0] > points[i - 1][1])
            arrowNum++;
        else
            // 若前一个气球与当前气球重叠，判断并更新最小的x_end
            points[i][1] = points[i][1] > points[i - 1][1] ? points[i - 1][1] : points[i][1];
    }
    return arrowNum;
}