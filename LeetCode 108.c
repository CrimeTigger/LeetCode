/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *traversal(int *nums, int left, int right)
{
    if (left > right) // 当区间 left > right的时候，就是空节点
        return NULL;
    int mid = left + ((right - left) / 2); // 取了中间位置，就开始以中间位置的元素构造节点
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = traversal(nums, left, mid - 1);   // root的左孩子接住下一层左区间的构造节点
    root->right = traversal(nums, mid + 1, right); // 右孩子接住下一层右区间构造的节点。
    return root;
}
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *result = traversal(nums, 0, numsSize - 1);
    return result;
}