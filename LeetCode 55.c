// 那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点！
// 贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool canJump(int *nums, int numsSize)
{
    int cover = 0;

    int i;
    // 只可能获取cover范围中的步数，所以i<=cover
    for (i = 0; i <= cover; ++i)
    {
        // 更新cover为从i出发能到达的最大值/cover的值中较大值
        cover = max(i + nums[i], cover);

        // 若更新后cover可以到达最后的元素，返回true
        if (cover >= numsSize - 1)
            return true;
    }

    return false;
}