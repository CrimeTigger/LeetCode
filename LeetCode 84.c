// ����ջ���˳���Ǵ�С�����ǴӴ�С��
int largestRectangleArea(int *heights, int heightsSize)
{
    int newHeightsSize = heightsSize + 2;
    int *newHeights[newHeightsSize];
    newHeights[0] = 0;                  // ����ͷ������Ԫ��0
    newHeights[newHeightsSize - 1] = 0; // ����β������Ԫ��0
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
                result = fmax(result, wid * heig); // ջ����ջ������һ��Ԫ���Լ�Ҫ��ջ������Ԫ�����������Ҫ���������ĸ߶ȺͿ��
            }
        }
        stack[top++] = i;
    }
    return result;
}