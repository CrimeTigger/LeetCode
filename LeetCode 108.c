/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *traversal(int *nums, int left, int right)
{
    if (left > right) // ������ left > right��ʱ�򣬾��ǿսڵ�
        return NULL;
    int mid = left + ((right - left) / 2); // ȡ���м�λ�ã��Ϳ�ʼ���м�λ�õ�Ԫ�ع���ڵ�
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = traversal(nums, left, mid - 1);   // root�����ӽ�ס��һ��������Ĺ���ڵ�
    root->right = traversal(nums, mid + 1, right); // �Һ��ӽ�ס��һ�������乹��Ľڵ㡣
    return root;
}
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *result = traversal(nums, 0, numsSize - 1);
    return result;
}