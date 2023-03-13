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
        {                       // ָ�������ʽڵ㣬���ʵ���ײ�
            stack[++top] = cur; // �����ʵĽڵ�Ž�ջ
            cur = cur->left;    // ��
        }
        else
        {
            cur = stack[top--];
            if (pre)
            { // ��
                result = fmin(result, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right; // ��
        }
    }
    return result;
}