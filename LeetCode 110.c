/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHeight(struct TreeNode *root)
{
    if (!root) return 0;
    int leftHeight = getHeight(root->left);
    if (leftHeight == -1) // 左
        return -1;
    int rightHeight = getHeight(root->right);
    if (rightHeight == -1) // 右
        return -1;
    return fabs(leftHeight - rightHeight) > 1 ? -1 : fmax(leftHeight, rightHeight) + 1; // 以当前节点为根节点的树的最大高度
}

bool isBalanced(struct TreeNode *root)
{
    return getHeight(root) == -1 ? false : true;
}