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
    // 若中序遍历数组中没有元素，则返回NULL
    if (!inorderSize)
        return NULL;
    // 创建一个新的结点，将node的val设置为后序遍历的最后一个元素
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = postorder[postorderSize - 1];

    // 通过线性查找找到中间结点在中序数组中的位置
    int index = linearSearch(inorder, inorderSize, postorder[postorderSize - 1]);

    // 左子树数组大小为index
    // 右子树的数组大小为数组大小减index减1（减的1为中间结点）
    int rightSize = inorderSize - index - 1;
    node->left = buildTree(inorder, index, postorder, index);
    node->right = buildTree(inorder + index + 1, rightSize, postorder + index, rightSize);
    return node;
}