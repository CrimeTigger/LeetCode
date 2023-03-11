/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth = INT_MIN; // ȫ�ֱ��� ��¼������
int result;             // ȫ�ֱ��� ����������ڵ����ֵ
void traversal(struct TreeNode *root, int depth)
{

    if (!root)
        return;
    if (!root->left && !root->right&&depth==0){
        result = root->val
        return ;
    }
    if (!root->left && !root->right)
    {
        if (depth > maxDepth)
        {
            maxDepth = depth;   // ����������
            result = root->val; // ���������������ֵ
        }
        return;
    }
    if (root->left)
    {            // ��
        depth++; // ��ȼ�һ
        traversal(root->left, depth);
        depth--; // ���ݣ���ȼ�һ
    }
    if (root->right)
    {            // ��
        depth++; // ��ȼ�һ
        traversal(root->right, depth);
        depth--; // ���ݣ���ȼ�һ
    }
    return;
}

int findBottomLeftValue(struct TreeNode *root)
{
    traversal(root, 0);
    return result;
}