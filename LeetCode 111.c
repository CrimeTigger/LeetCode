//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ���������ע����Ҷ�ӽڵ�
int getDepth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int leftDepth = getDepth(node->left);   // ��
    int rightDepth = getDepth(node->right); // ��
                                            // ��
    // ��һ��������Ϊ�գ��Ҳ�Ϊ�գ���ʱ��������͵�
    if (node->left == NULL && node->right != NULL)
    {

        return 1 + rightDepth;
    }

    // ��һ��������Ϊ�գ���Ϊ�գ���ʱ��������͵�
    if (node->left != NULL && node->right == NULL)
    {

        return 1 + leftDepth;
    }
    int result = 1 + min(leftDepth, rightDepth);
    return result;
}

int minDepth(TreeNode *root)
{
    return getDepth(root);
}
