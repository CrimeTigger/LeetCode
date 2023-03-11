int linearSearch(int *arr, int arrSize, int key)
{
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    // ���������������û��Ԫ�أ��򷵻�NULL
    if (!inorderSize)
        return NULL;
    // ����һ���µĽ�㣬��node��val����Ϊ������������һ��Ԫ��
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = postorder[postorderSize - 1];

    // ͨ�����Բ����ҵ��м��������������е�λ��
    int index = linearSearch(inorder, inorderSize, postorder[postorderSize - 1]);

    // �����������СΪindex
    // �������������СΪ�����С��index��1������1Ϊ�м��㣩
    int rightSize = inorderSize - index - 1;
    node->left = buildTree(inorder, index, postorder, index);
    node->right = buildTree(inorder + index + 1, rightSize, postorder + index, rightSize);
    return node;
}