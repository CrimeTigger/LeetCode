/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;
    // 重新定义新的节点，不修改原有两个树的结构
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = root1->val + root2->val;// 中
    root->left = mergeTrees(root1->left, root2->left); // 左
    root->right = mergeTrees(root1->right, root2->right);// 右
    return root;
}