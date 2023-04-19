/* 解法2 单调栈 + 哈希表, 时间复杂度为O(n1+n2) */
/* uthash结构体 */
typedef struct
{
    int num;
    int greater;
    UT_hash_handle hh;
} NumHash;

NumHash *g_head;

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    int i, j;
    int *res = (int *)malloc(sizeof(int) * nums1Size);
    int stack[nums2Size];
    int top = 0;
    NumHash *s = NULL;
    g_head = NULL;

    /* 用单调栈求出nums2元素的下一个更大值, 并记录在hash表中 */
    for (i = nums2Size - 1; i >= 0; i--)
    {
        while (top != 0 && nums2[i] >= stack[top - 1])
        {
            top--;
        }
        s = (NumHash *)malloc(sizeof(NumHash));
        s->num = nums2[i];
        s->greater = (top == 0) ? -1 : stack[top - 1];
        HASH_ADD_INT(g_head, num, s);
        stack[top++] = nums2[i];
    }

    /* 遍历nums1元素, 在hash表中找到更大元素输出即可 */
    for (i = 0; i < nums1Size; i++)
    {
        HASH_FIND_INT(g_head, &nums1[i], s);
        res[i] = s->greater;
    }
    *returnSize = nums1Size;
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} NumHash;
int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    NumHash *nmap = malloc(sizeof(NumHash));
    int *result = malloc(sizeof(nums1Size));
    memset(result, -1, sizeof(result)); // result数组如果某位置没有被赋值，那么就应该是是-1
    *returnSize = nums1Size;
    int stack[nums2Size + 1];
    int top = 0;
    for (int i = 0; i < nums1Size; i++)
    {
        NumHash *tmp = malloc(sizeof(NumHash));
        tmp->key = nums1[i];
        tmp->val = i;
        HASH_ADD_INT(nmap, key, tmp);
    }
    stack[top++] = 0;
    for (int i = 1; i < nums2Size; i++)
    {
        while (top > 0 && nums2[i] > nums2[stack[top - 1]])
        {
            int key = nums2[stack[top - 1]];
            NumHash *tmp;
            HASH_FIND_INT(nmap, &key, tmp); // map来做映射了。根据数值快速找到下标，还可以判断nums2[i]是否在nums1中出现过
            if (tmp)
            {
                result[tmp->val] = nums2[i];
            }
            top--;
        }
    }
    return result;
}