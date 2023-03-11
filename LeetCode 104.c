
//�����������ȵݹ�
int maxDepth(struct TreeNode* root){
    //��������ΪNULL������0
    if(!root)
        return 0;
    
    //������������
    int left = maxDepth(root->left);
    //������������
    int right = maxDepth(root->right);
    //�����������Ⱥ���������ȵĽϴ�ֵ
    int max = left > right ? left : right;
    //���ؽϴ�ֵ+1��1Ϊ��ǰ������
    return max + 1;
}



//�����������ȵ���
int maxDepth(struct TreeNode* root){
    //��������ڵ�ΪNULL������0
    if(!root)
        return 0;
    
    int depth = 0;
    //���ٶ��пռ�
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 6000);
    int queueFront = 0;
    int queueEnd = 0;

    //����������
    queue[queueEnd++] = root;

    int queueSize;
    //�����ǰ������Ԫ�ظ���
    while(queueSize = queueEnd - queueFront) {
        int i;
        //����ǰ�����н�������������������ǵ������������
        for(i = 0; i < queueSize; i++) {
            struct TreeNode* tempNode = queue[queueFront + i];
            if(tempNode->left)
                queue[queueEnd++] = tempNode->left;
            if(tempNode->right)
                queue[queueEnd++] = tempNode->right;
        }
        //���¶�ͷ�±�
        queueFront += queueSize;
        //���+1
        depth++;
    }
    return depth;
}