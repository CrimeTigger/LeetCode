// 要从覆盖范围出发，不管怎么跳，覆盖范围内一定是可以跳到的，以最小的步数增加覆盖范围，覆盖范围一旦覆盖了终点，得到的就是最小步数！
// 这里需要统计两个覆盖范围，当前这一步的最大覆盖和下一步最大覆盖

// 版本一

int jump(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    int curDistance = 0;  // 当前覆盖最远距离下标
    int count = 0;        // 记录走的最大步数
    int nextDistance = 0; // 下一步覆盖最远距离下标
    for (int i = 0; i < numsSize; i++)
    {
        nextDistance = fmax(nums[i] + i, nextDistance);
        if (i == curDistance)
        { // 遇到当前覆盖最远距离下标
            if (curDistance < numsSize - 1)
            {                               // 如果当前覆盖最远距离下标不是终点
                count++;                    // 需要走下一步
                curDistance = nextDistance; // 更新当前覆盖最远距离下标（相当于加油了）
                if (nextDistance >= numsSize - 1)
                    break; // 下一步的覆盖范围已经可以达到终点，结束循环
            }
            else
                break; // 当前覆盖最远距到达集合终点，不用做count++操作了，直接结束
        }
    }
    return count;
}

// 其精髓在于控制移动下标i只移动到nums.size() - 2的位置，所以移动下标只要遇到当前覆盖最远距离的下标，直接步数加一，不用考虑别的了
int jump(int *nums, int numsSize)
{
    int curDistance = 0;  // 当前覆盖的最远距离下标
    int ans = 0;          // 记录走的最大步数
    int nextDistance = 0; // 下一步覆盖的最远距离下标
    for (int i = 0; i < numsSize - 1; i++)
    {                                                   // 注意这里是小于nums.size() - 1，这是关键所在
        nextDistance = fmax(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
        if (i == curDistance)
        {                               // 遇到当前覆盖的最远距离下标
            curDistance = nextDistance; // 更新当前覆盖的最远距离下标
            ans++;
        }
    }
    return ans;
}