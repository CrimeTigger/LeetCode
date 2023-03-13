/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode *root)
{
    if (!root)
        return NULL;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode));
    int top = -1;
    struct TreeNode *cur = root;
    struct TreeNode *pre = NULL;
    int result = INT_MAX;
    while (cur || top > -1)
    {
        if (cur)
        {                       // 指针来访问节点，访问到最底层
            stack[++top] = cur; // 将访问的节点放进栈
            cur = cur->left;    // 左
        }
        else
        {
            cur = stack[top--];
            if (pre)
            { // 中
                result = fmin(result, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right; // 右
        }
    }
    return result;
}