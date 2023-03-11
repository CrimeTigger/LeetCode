/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
    if (!root) // 当前为叶子节点NULL，直接插入
    {
        struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (root->val > val) // 插入左子树
        root->left = insertIntoBST(root->left, val);
    if (root->val < val) // 插入右子树
        root->right = insertIntoBST(root->right, val);
    return root;
}