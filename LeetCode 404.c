/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 递归:

int sumOfLeftLeaves(struct TreeNode *root)//当前节点为父节点
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

//迭代

int sumOfLeftLeaves(struct TreeNode *root)
{
    struct TreeNode *stack[1000];
    int stackTop = 0;

    // 若传入root结点不为空，将其入栈
    if (root)
        stack[stackTop++] = root;

    int sum = 0;
    // 若栈不为空，进行循环
    while (stackTop)
    {
        // 出栈栈顶元素
        struct TreeNode *topNode = stack[--stackTop];
        // 若栈顶元素的左孩子为左叶子结点，将其值加入sum中
        if (topNode->left && (!topNode->left->left && !topNode->left->right))
            sum += topNode->left->val;

        // 若当前栈顶结点有左右孩子。将他们加入栈中进行遍历
        if (topNode->right)
            stack[stackTop++] = topNode->right;
        if (topNode->left)
            stack[stackTop++] = topNode->left;
    }
    return sum;
}