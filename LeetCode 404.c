/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// �ݹ�:

int sumOfLeftLeaves(struct TreeNode *root)//��ǰ�ڵ�Ϊ���ڵ�
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 0;
    int leftNum = sumOfLeftLeaves(root->left);
    if (root->left && !root->left->left && !root->left->right)
    {
        leftNum = root->left->val;
    }
    int rightNum = sumOfLeftLeaves(root->right);
    return leftNum + rightNum;
}

//����

int sumOfLeftLeaves(struct TreeNode *root)
{
    struct TreeNode *stack[1000];
    int stackTop = 0;

    // ������root��㲻Ϊ�գ�������ջ
    if (root)
        stack[stackTop++] = root;

    int sum = 0;
    // ��ջ��Ϊ�գ�����ѭ��
    while (stackTop)
    {
        // ��ջջ��Ԫ��
        struct TreeNode *topNode = stack[--stackTop];
        // ��ջ��Ԫ�ص�����Ϊ��Ҷ�ӽ�㣬����ֵ����sum��
        if (topNode->left && (!topNode->left->left && !topNode->left->right))
            sum += topNode->left->val;

        // ����ǰջ����������Һ��ӡ������Ǽ���ջ�н��б���
        if (topNode->right)
            stack[stackTop++] = topNode->right;
        if (topNode->left)
            stack[stackTop++] = topNode->left;
    }
    return sum;
}