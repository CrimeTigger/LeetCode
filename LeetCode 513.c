/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth = INT_MIN; // 全局变量 记录最大深度
int result;             // 全局变量 最大深度最左节点的数值
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
            maxDepth = depth;   // 更新最大深度
            result = root->val; // 最大深度最左面的数值
        }
        return;
    }
    if (root->left)
    {            // 左
        depth++; // 深度加一
        traversal(root->left, depth);
        depth--; // 回溯，深度减一
    }
    if (root->right)
    {            // 右
        depth++; // 深度加一
        traversal(root->right, depth);
        depth--; // 回溯，深度减一
    }
    return;
}

int findBottomLeftValue(struct TreeNode *root)
{
    traversal(root, 0);
    return result;
}