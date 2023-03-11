/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *pre = NULL;
bool isValidBST(struct TreeNode *root)
{
    if (!root)
        return true;
    bool left = isValidBST(root->left);
    if (pre && pre->val >= root->val)
        return false;
    pre = root;
    bool right = isValidBST(root->right);
    return left && right;
}