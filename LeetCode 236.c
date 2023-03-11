/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (!root)
        return root;//遇到空的话
    if (root == q || root == p)//如果 root == q，或者 root == p，说明找到 q p ，则将其返回
        return root;
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);// 左
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);// 右
    if (left && right)
        return root; //如果left 和 right都不为空，说明此时root就是最近公共节点
    if (!left && right)//如果left为空，right不为空，就返回right
        return right;
    if (left && !right)
        return left;
    if (left == NULL)
        return right;
    return left;
}