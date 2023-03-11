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
    if (!root) // ��ǰΪҶ�ӽڵ�NULL��ֱ�Ӳ���
    {
        struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (root->val > val) // ����������
        root->left = insertIntoBST(root->left, val);
    if (root->val < val) // ����������
        root->right = insertIntoBST(root->right, val);
    return root;
}