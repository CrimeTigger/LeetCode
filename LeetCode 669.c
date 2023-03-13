/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *trimBST(struct TreeNode *root, int low, int high)
{
    if (!root)
        return root;
    if (root->val < low) // 如果root（当前节点）的元素小于low的数值，那么应该递归右子树，并返回右子树符合条件的头结点
    {
        struct TreeNode *right = trimBST(root->right, low, high);
        return right;
    }
    if (root->val > high) // 如果root(当前节点)的元素大于high的，那么应该递归左子树，并返回左子树符合条件的头结点。
    {
        struct TreeNode *left = trimBST(root->left, low, high);
        return left;
    }
    root->left = trimBST(root->left, low, high);   // root->left接入符合条件的左孩子
    root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
    return root;
}