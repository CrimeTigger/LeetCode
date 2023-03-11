/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// µÝ¹é
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

// µü´ú
struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root) 
        return root;
    while (root)
    {
        if (root->val > val) 
            root = root->left; //Íù×ó
        else if (root->val < val) //ÍùÓÒ
            root = root->right;
        else
            return root;
    }
    return NULL;
}