// 单调栈里的顺序，是从小到大还是从大到小。
int largestRectangleArea(int *heights, int heightsSize)
{
    int newHeightsSize = heightsSize + 2;
    int *newHeights[newHeightsSize];
    newHeights[0] = 0;                  // 数组头部加入元素0
    newHeights[newHeightsSize - 1] = 0; // 数组尾部加入元素0
    for (int i = 0; i < heightsSize; i++)
    {
        newHeights[i + 1] = heights[i];
    }
    int stack[newHeightsSize + 1];
    int top = 0;
    int result = 0;
    for (int i = 0; i < newHeightsSize; i++)
    {
        while (top > 0 && newHeights[i] < newHeights[stack[top - 1]])
        {
            int mid = stack[top - 1];
            top--;
            if (top > 0)
            {
                int left = stack[top - 1];
                int right = i;
                int wid = right - left - 1;
                int heig = newHeights[mid];
                result = fmax(result, wid * heig); // 栈顶和栈顶的下一个元素以及要入栈的三个元素组成了我们要求最大面积的高度和宽度
            }
        }
        stack[top++] = i;
    }
    return result;
}