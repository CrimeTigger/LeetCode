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
    if (root->val < low) // ���root����ǰ�ڵ㣩��Ԫ��С��low����ֵ����ôӦ�õݹ�������������������������������ͷ���
    {
        struct TreeNode *right = trimBST(root->right, low, high);
        return right;
    }
    if (root->val > high) // ���root(��ǰ�ڵ�)��Ԫ�ش���high�ģ���ôӦ�õݹ�������������������������������ͷ��㡣
    {
        struct TreeNode *left = trimBST(root->left, low, high);
        return left;
    }
    root->left = trimBST(root->left, low, high);   // root->left�����������������
    root->right = trimBST(root->right, low, high); // root->right��������������Һ���
    return root;
}