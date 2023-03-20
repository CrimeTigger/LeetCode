
// 那么局部最优：当前累加rest[i]的和curSum一旦小于0，起始位置至少要是i+1，因为从i之前开始一定不行。全局最优：找到可以跑一圈的起始位置。
int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
    int curSum = 0;
    int totalSum = 0;
    int start = 0;

    int i;
    for (i = 0; i < gasSize; ++i)
    {
        // 当前i站中加油量与耗油量的差
        int diff = gas[i] - cost[i];

        curSum += diff;
        totalSum += diff;

        // 若0到i的加油量都为负，则开始位置应为i+1
        if (curSum < 0)
        {
            curSum = 0;
            // 当i + 1 == gasSize时，totalSum < 0（此时i为gasSize - 1)，油车不可能返回原点
            start = i + 1;
        }
    }

    // 若总和小于0，加油车无论如何都无法返回原点。返回-1
    if (totalSum < 0)
        return -1;

    return start;
}