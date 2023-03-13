/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// ������������������
int pre; // ��¼ǰһ���ڵ����ֵ
void traversal(struct TreeNode *root)
{
    if (!root)
        return;
    traversal(root->right); // ��
    root->val += pre;       // ��
    pre = root->val;
    traversal(root->left); // ��
    return;
}
struct TreeNode *convertBST(struct TreeNode *root)
{
    pre = 0;
    traversal(root);
    return root;
}