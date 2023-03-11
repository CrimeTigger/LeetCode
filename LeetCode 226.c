//递归法
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    //交换结点的左右孩子（中）
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    左
    invertTree(root->left);
    //右
    invertTree(root->right);
    return root;
}


//迭代法：深度优先遍历
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    //存储结点的栈
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int stackTop = 0;
    //将根节点入栈
    stack[stackTop++] = root;
    //若栈中还有元素（进行循环）
    while(stackTop) {
        //取出栈顶元素
        struct TreeNode* temp = stack[--stackTop];
        //交换结点的左右孩子
        struct TreeNode* tempNode = temp->right;
        temp->right = temp->left;
        temp->left = tempNode;
        //若当前结点有左右孩子，将其入栈
        if(temp->right)
            stack[stackTop++] = temp->right;
        if(temp->left)
            stack[stackTop++] = temp->left;
    }
    return root;
}