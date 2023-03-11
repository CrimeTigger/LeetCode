/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// �ݹ�
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root || root->val == val)
        return root;
    struct TreeNode *result = NULL;
    if (root->val > val)
        result = searchBST(root->left, val);
    if (root->val < val)
        result = searchBST(root->right, val);
    return result;
}

// ����
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root) 
        return root;
    while (root)
    {
        if (root->val > val) 
            root = root->left; //����
        else if (root->val < val) //����
            root = root->right;
        else
            return root;
    }
    return NULL;
}