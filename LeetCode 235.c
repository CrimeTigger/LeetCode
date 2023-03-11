/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//��Ҫע����Ǵ�ʱ��֪��p��q˭������������Ҫ�ж�
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (!root)
        return root;
    if (root->val > p->val && root->val > q->val) //��ô��� cur->val ���� p->val��ͬʱ cur->val ����q->val����ô��Ӧ�����������˵��Ŀ���������������ϣ�
    {
        struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left)
        {
            return left;
        }
    }
    if (root->val < p->val && root->val < q->val) //��� cur->val С�� p->val��ͬʱ cur->val С�� q->val����ô��Ӧ�����ұ�����Ŀ����������������
    {
        struct TreeNode *right = lowestCommonAncestor(root->right, q, p);
        if (right)
        {
            return right;
        }
    }
    //ʣ�µ����������cur�ڵ������䣨p->val <= cur->val && cur->val <= q->val������ ��q->val <= cur->val && cur->val <= p->val���У���ôcur����������������ˣ�ֱ�ӷ���cur��
    return root;
}