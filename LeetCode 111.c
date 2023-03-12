//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。，注意是叶子节点
int getDepth(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int leftDepth = getDepth(node->left);   // 左
    int rightDepth = getDepth(node->right); // 右
                                            // 中
    // 当一个左子树为空，右不为空，这时并不是最低点
    if (node->left == NULL && node->right != NULL)
    {

        return 1 + rightDepth;
    }

    // 当一个右子树为空，左不为空，这时并不是最低点
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
