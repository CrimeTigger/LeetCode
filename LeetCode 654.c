/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// ������һ����õ���ǰ���������Ϊ�ȹ����м�ڵ㣬Ȼ��ݹ鹹����������������
//  ������ҿ�����[left, right)�����������
struct TreeNode *traversal(int *nums, int left, int right)
{
    if (left >= right)
        return NULL;
    // �ָ���±꣺maxValueIndex
    int maxNum = left;
    for (int i = left + 1; i < right; i++)
    {
        if (nums[i] > nums[maxNum])
            maxNum = i;
    }
    struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
    newNode->val = nums[maxNum];
    // ����ҿ���[left, maxNum)
    newNode->left = traversal(nums, left, maxNum);
    // ����ҿ���[maxNum + 1, right)
    newNode->right = traversal(nums, maxNum + 1, right);
    return newNode;
}
struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize)
{
    struct TreeNode *node = traversal(nums, 0, numsSize);
    return node;
}