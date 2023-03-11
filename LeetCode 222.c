// 递归法
int countNodes(struct TreeNode *root)
{
    // 若传入结点不存在，返回0
    if (!root)
        return 0;
    // 算出左右子树的结点总数
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    // 返回左右子树结点总数+1
    return leftCount + rightCount + 1;
}

int countNodes(struct TreeNode *root)
{
    return getNodes(root);
}

// 迭代法
int countNodes(struct TreeNode *root)
{
    // 记录结点总数
    int totalNum = 0;
    // 开辟栈空间
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int stackTop = 0;
    // 如果root结点不为NULL，则将其入栈。若为NULL，则不会进入遍历，返回0
    if (root)
        stack[stackTop++] = root;
    // 若栈中有结点存在，则进行遍历
    while (stackTop)
    {
        // 取出栈顶元素
        struct TreeNode *tempNode = stack[--stackTop];
        // 结点总数+1
        totalNum++;
        // 若栈顶结点有左右孩子，将它们入栈
        if (tempNode->left)
            stack[stackTop++] = tempNode->left;
        if (tempNode->right)
            stack[stackTop++] = tempNode->right;
    }
    return totalNum;
}

// 满二叉树
int countNodes(struct TreeNode *root)
{
    if (!root)
        return 0;
    int leftDepth = 0;
    int rightDepth = 0;
    struct TreeNode *rightNode = root->right;
    struct TreeNode *leftNode = root->left;
    // 求出左子树深度
    while (leftNode)
    {
        leftNode = leftNode->left;
        leftDepth++;
    }

    // 求出右子树深度
    while (rightNode)
    {
        rightNode = rightNode->right;
        rightDepth++;
    }
    // 若左右子树深度相同，为满二叉树。结点个数为2^height-1
    if (rightDepth == leftDepth)
    {
        return (2 << leftDepth) - 1;
    }
    // 否则返回左右子树的结点个数+1
    int leftTreeNum = countNodes(root->left);    // 左
    int rightTreeNum = countNodes(root->right);  // 右
    int result = leftTreeNum + rightTreeNum + 1; // 中
    return result;
}