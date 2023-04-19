// 单调栈解法
int trap(int *height, int heightSize)
{
    int sum = 0;
    int stack[heightSize + 1]; // 存着下标，计算的时候用下标对应的柱子高度
    int top = 0;
    for (int i = 0; i < heightSize; i++)
    {
        while (top > 0 && height[i] > height[stack[top - 1]])
        {
            int mid = height[stack[top - 1]];
            top--;
            if (top > 0)
            {
                int minHeight = fmin(height[i], height[stack[top - 1]]) - mid; // 雨水高度是 min(凹槽左边高度, 凹槽右边高度) - 凹槽底部高度
                int width = i - stack[top - 1] - 1;                            // 雨水的宽度是 凹槽右边的下标 - 凹槽左边的下标 - 1（因为只求中间宽度）
                sum += minHeight * width;
            }
        }
        stack[top++] = i;
    }
    return sum;
}

// 双指针方法
int trap(int *height, int heightSize)
{
    int ans = 0;
    int left = 0, right = heightSize - 1; // 初始化两个指针到左右两边
    int leftMax = 0, rightMax = 0;        // 这两个值用来记录左右的“壁”的最高值
    while (left < right)
    { // 两个指针重合就结束
        leftMax = fmax(leftMax, height[left]);
        rightMax = fmax(rightMax, height[right]);
        if (leftMax < rightMax)
        {
            ans += leftMax - height[left]; // 这里考虑的是下标为left的“底”能装多少水
            ++left;                        // 指针的移动次序是这个方法的关键
            // 这里左指针右移是因为左“墙”较矮，左边这一片实际情况下的盛水量是受制于这个矮的左“墙”的
            // 而较高的右边在实际情况下的限制条件可能不是当前的左“墙”，比如限制条件可能是右“墙”，就能装更高的水，
        }
        else
        {
            ans += rightMax - height[right]; // 同理，考虑下标为right的元素
            --right;
        }
    }
    return ans;
}