//�ݹ鷨
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    //�����������Һ��ӣ��У�
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    ��
    invertTree(root->left);
    //��
    invertTree(root->right);
    return root;
}


//��������������ȱ���
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return NULL;
    //�洢����ջ
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int stackTop = 0;
    //�����ڵ���ջ
    stack[stackTop++] = root;
    //��ջ�л���Ԫ�أ�����ѭ����
    while(stackTop) {
        //ȡ��ջ��Ԫ��
        struct TreeNode* temp = stack[--stackTop];
        //�����������Һ���
        struct TreeNode* tempNode = temp->right;
        temp->right = temp->left;
        temp->left = tempNode;
        //����ǰ��������Һ��ӣ�������ջ
        if(temp->right)
            stack[stackTop++] = temp->right;
        if(temp->left)
            stack[stackTop++] = temp->left;
    }
    return root;
}