/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *robTree(struct TreeNode *root)
{
    int *res[2] = {0, 0};
    if (!root)
        return res;
    int *left = robTree(root->left);
    int *right = robTree(root->right);
    res[1] = root->val + left[0] + right[0];
    res[0] = fmax(left[0] + left[1]) + fmax(right[0], right[1]);
    return res;
}
int rob(struct TreeNode *root)
{
    int *res = robTree(root);
    return fmax(res[0], res[1]);
}