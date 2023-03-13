/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 构造树一般采用的是前序遍历，因为先构造中间节点，然后递归构造左子树和右子树
//  在左闭右开区间[left, right)，构造二叉树
struct TreeNode *traversal(int *nums, int left, int right)
{
    if (left >= right)
        return NULL;
    // 分割点下标：maxValueIndex
    int maxNum = left;
    for (int i = left + 1; i < right; i++)
    {
        if (nums[i] > nums[maxNum])
            maxNum = i;
    }
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->val = nums[maxNum];
    // 左闭右开：[left, maxNum)
    newNode->left = traversal(nums, left, maxNum);
    // 左闭右开：[maxNum + 1, right)
    newNode->right = traversal(nums, maxNum + 1, right);
    return newNode;
}
struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    struct TreeNode *node = traversal(nums, 0, numsSize);
    return node;
}