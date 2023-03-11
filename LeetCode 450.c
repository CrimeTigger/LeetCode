/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
    if (!root)
        return root; // ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
    if (root->val == key)
    {
        if (!root->left && !root->right) // �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
        {
            free(root);
            return NULL;
        }
        else if (!root->left && root->right) // �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
        {
            free(root);
            return root->right;
        }
        else if (root->left && !root->right) // ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
        {
            free(root);
            return root->left;
        }
        else// ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
            // ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
        {
            struct TreeNode *cur = root->right;
            while (cur->left)// ��������������Ľڵ�
            {
                cur = cur->left;
            }
            cur->left = root->left;// ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
            struct TreeNode *temp = root;//��root�ڵ㱣��һ�£�������ɾ��
            root = root->right;// ���ؾ�root���Һ�����Ϊ��root
            free(temp);// �ͷŽڵ��ڴ�
            return root;
        }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}