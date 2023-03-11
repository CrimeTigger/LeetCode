// �ݹ鷨
int countNodes(struct TreeNode *root)
{
    // �������㲻���ڣ�����0
    if (!root)
        return 0;
    // ������������Ľ������
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    // �������������������+1
    return leftCount + rightCount + 1;
}

int countNodes(struct TreeNode *root)
{
    return getNodes(root);
}

// ������
int countNodes(struct TreeNode *root)
{
    // ��¼�������
    int totalNum = 0;
    // ����ջ�ռ�
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int stackTop = 0;
    // ���root��㲻ΪNULL��������ջ����ΪNULL���򲻻�������������0
    if (root)
        stack[stackTop++] = root;
    // ��ջ���н����ڣ�����б���
    while (stackTop)
    {
        // ȡ��ջ��Ԫ��
        struct TreeNode *tempNode = stack[--stackTop];
        // �������+1
        totalNum++;
        // ��ջ����������Һ��ӣ���������ջ
        if (tempNode->left)
            stack[stackTop++] = tempNode->left;
        if (tempNode->right)
            stack[stackTop++] = tempNode->right;
    }
    return totalNum;
}

// ��������
int countNodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    int leftDepth = 0;
    int rightDepth = 0;
    struct TreeNode *rightNode = root->right;
    struct TreeNode *leftNode = root->left;
    // ������������
    while (leftNode)
    {
        leftNode = leftNode->left;
        leftDepth++;
    }

    // ������������
    while (rightNode)
    {
        rightNode = rightNode->right;
        rightDepth++;
    }
    // ���������������ͬ��Ϊ����������������Ϊ2^height-1
    if (rightDepth == leftDepth)
    {
        return (2 << leftDepth) - 1;
    }
    // ���򷵻����������Ľ�����+1
    int leftTreeNum = countNodes(root->left);    // ��
    int rightTreeNum = countNodes(root->right);  // ��
    int result = leftTreeNum + rightTreeNum + 1; // ��
    return result;
}