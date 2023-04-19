// ����ջ�ⷨ
int trap(int *height, int heightSize)
{
    int sum = 0;
    int stack[heightSize + 1]; // �����±꣬�����ʱ�����±��Ӧ�����Ӹ߶�
    int top = 0;
    for (int i = 0; i < heightSize; i++)
    {
        while (top > 0 && height[i] > height[stack[top - 1]])
        {
            int mid = height[stack[top - 1]];
            top--;
            if (top > 0)
            {
                int minHeight = fmin(height[i], height[stack[top - 1]]) - mid; // ��ˮ�߶��� min(������߸߶�, �����ұ߸߶�) - ���۵ײ��߶�
                int width = i - stack[top - 1] - 1;                            // ��ˮ�Ŀ���� �����ұߵ��±� - ������ߵ��±� - 1����Ϊֻ���м��ȣ�
                sum += minHeight * width;
            }
        }
        stack[top++] = i;
    }
    return sum;
}

// ˫ָ�뷽��
int trap(int *height, int heightSize)
{
    int ans = 0;
    int left = 0, right = heightSize - 1; // ��ʼ������ָ�뵽��������
    int leftMax = 0, rightMax = 0;        // ������ֵ������¼���ҵġ��ڡ������ֵ
    while (left < right)
    { // ����ָ���غϾͽ���
        leftMax = fmax(leftMax, height[left]);
        rightMax = fmax(rightMax, height[right]);
        if (leftMax < rightMax)
        {
            ans += leftMax - height[left]; // ���￼�ǵ����±�Ϊleft�ġ��ס���װ����ˮ
            ++left;                        // ָ����ƶ���������������Ĺؼ�
            // ������ָ����������Ϊ��ǽ���ϰ��������һƬʵ������µ�ʢˮ�������������������ǽ����
            // ���ϸߵ��ұ���ʵ������µ������������ܲ��ǵ�ǰ����ǽ�����������������������ҡ�ǽ��������װ���ߵ�ˮ��
        }
        else
        {
            ans += rightMax - height[right]; // ͬ�������±�Ϊright��Ԫ��
            --right;
        }
    }
    return ans;
}