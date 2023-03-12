/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *pre = NULL;
bool isValidBST(struct TreeNode *root)
{
    if (!root)
        return true;
    bool left = isValidBST(root->left);
    if (pre && pre->val >= root->val)
        return false;
    pre = root;
    bool right = isValidBST(root->right);
    return left && right;
}

// 迭代
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode *root)
{
    if (!root)
        return true;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode));
    int top = -1;
    struct TreeNode *cur = root;
    struct TreeNode *pre = NULL;
    while (root || top > -1)
    {
        if (root)
        {
            stack[++top] = cur; // 左
            cur = cur->left;
        }
        else
        {
            cur = stack[top--]; // 中
            if (pre && cur->val < pre->val)
                return false;
            pre = cur;
            cur = cur->right; // 右
        }
    }
    return true;
}
