/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//需要注意的是此时不知道p和q谁大，所以两个都要判断
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (!root)
        return root;
    if (root->val > p->val && root->val > q->val) //那么如果 cur->val 大于 p->val，同时 cur->val 大于q->val，那么就应该向左遍历（说明目标区间在左子树上）
    {
        struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left)
        {
            return left;
        }
    }
    if (root->val < p->val && root->val < q->val) //如果 cur->val 小于 p->val，同时 cur->val 小于 q->val，那么就应该向右遍历（目标区间在右子树）
    {
        struct TreeNode *right = lowestCommonAncestor(root->right, q, p);
        if (right)
        {
            return right;
        }
    }
    //剩下的情况，就是cur节点在区间（p->val <= cur->val && cur->val <= q->val）或者 （q->val <= cur->val && cur->val <= p->val）中，那么cur就是最近公共祖先了，直接返回cur。
    return root;
}