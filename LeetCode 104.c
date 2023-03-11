
//二叉树最大深度递归
int maxDepth(struct TreeNode* root){
    //若传入结点为NULL，返回0
    if(!root)
        return 0;
    
    //求出左子树深度
    int left = maxDepth(root->left);
    //求出右子树深度
    int right = maxDepth(root->right);
    //求出左子树深度和右子树深度的较大值
    int max = left > right ? left : right;
    //返回较大值+1（1为当前层数）
    return max + 1;
}



//二叉树最大深度迭代
int maxDepth(struct TreeNode* root){
    //若传入根节点为NULL，返回0
    if(!root)
        return 0;
    
    int depth = 0;
    //开辟队列空间
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 6000);
    int queueFront = 0;
    int queueEnd = 0;

    //将根结点入队
    queue[queueEnd++] = root;

    int queueSize;
    //求出当前队列中元素个数
    while(queueSize = queueEnd - queueFront) {
        int i;
        //若当前队列中结点有左右子树，则将它们的左右子树入队
        for(i = 0; i < queueSize; i++) {
            struct TreeNode* tempNode = queue[queueFront + i];
            if(tempNode->left)
                queue[queueEnd++] = tempNode->left;
            if(tempNode->right)
                queue[queueEnd++] = tempNode->right;
        }
        //更新队头下标
        queueFront += queueSize;
        //深度+1
        depth++;
    }
    return depth;
}