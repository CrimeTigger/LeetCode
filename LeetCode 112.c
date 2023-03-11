/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool traversal(struct TreeNode *root, int count)
{
    if (!root->left && !root->right && count == 0)
        return true;
    if (!root->left && !root->right)
        return false;
    if (root->left)
    {
        // if(hasPathSum(root->left,targetSum-root->left->val)) return true;
        count -= root->left->val; // 递归，处理节点;
        if (traversal(root->left, count))
            return true;
        count += root->left->val; // 回溯，撤销处理结果
    }
    if (root->right)
    {
        // if(hasPathSum(root->right,targetSum-root->right->val)) return true;
        count -= root->right->val; // 递归，处理节点;
        if (traversal(root->right, count))
            return true;
        count += root->right->val; // 回溯，撤销处理结果
    }
    return false;
}
bool hasPathSum(struct TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    return traversal(root, targetSum - root->val);
}