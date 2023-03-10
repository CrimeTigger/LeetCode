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
        return root; // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
    if (root->val == key)
    {
        if (!root->left && !root->right) // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        {
            free(root);
            return NULL;
        }
        else if (!root->left && root->right) // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
        {
            free(root);
            return root->right;
        }
        else if (root->left && !root->right) // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
        {
            free(root);
            return root->left;
        }
        else// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
        {
            struct TreeNode *cur = root->right;
            while (cur->left)// 找右子树最左面的节点
            {
                cur = cur->left;
            }
            cur->left = root->left;// 把要删除的节点（root）左子树放在cur的左孩子的位置
            struct TreeNode *temp = root;//把root节点保存一下，下面来删除
            root = root->right;// 返回旧root的右孩子作为新root
            free(temp);// 释放节点内存
            return root;
        }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}