/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void searchBST(struct TreeNode *cur)
{
    if (!cur)
        return;
    searchBST(cur->left);
    if (!pre)
    {
        count = 1;
    }
    else if (pre->val == cur->val)
    {
        count++;
    }
    else
    {
        count = 1;
    }
    pre = cur;
    if (count == maxCount)
    {
        ret[index++] = cur->val;
    }
    if (count > maxCount)
    {
        maxCount = count;
        meset(ret, 0, sizeof(ret));
        index = 0;
        ret[index++] = cur->val;
    }
    searchBST(cur->right);
    return;
}
int *findMode(struct TreeNode *root, int *returnSize)
{
    int *ret = malloc(sizeof(int));
    int index = 0;
    int count = 0, maxCount = 0;
    struct TreeNode *pre = NULL;
    searchBST(root);
}