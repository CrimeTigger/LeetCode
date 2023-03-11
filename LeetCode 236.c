/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (!root)
        return root;//�����յĻ�
    if (root == q || root == p)//��� root == q������ root == p��˵���ҵ� q p �����䷵��
        return root;
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);// ��
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);// ��
    if (left && right)
        return root; //���left �� right����Ϊ�գ�˵����ʱroot������������ڵ�
    if (!left && right)//���leftΪ�գ�right��Ϊ�գ��ͷ���right
        return right;
    if (left && !right)
        return left;
    if (left == NULL)
        return right;
    return left;
}