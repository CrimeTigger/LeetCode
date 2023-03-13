/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 反中序遍历这个二叉树
int pre; // 记录前一个节点的数值
void traversal(struct TreeNode *root)
{
    if (!root)
        return;
    traversal(root->right); // 右
    root->val += pre;       // 中
    pre = root->val;
    traversal(root->left); // 左
    return;
}
struct TreeNode *convertBST(struct TreeNode *root)
{
    pre = 0;
    traversal(root);
    return root;
}