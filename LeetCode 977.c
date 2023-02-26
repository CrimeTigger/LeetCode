int* sortedSquares(int* nums, int numsSize, int* returnSize){
    //���ص������С����ԭ�����С
    *returnSize = numsSize;
    //��������ָ�룬rightָ���������һλԪ�أ�leftָ�������һλԪ��
    int right = numsSize - 1;
    int left = 0;

    //���Ҫ���صĽ������
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int index;
    for(index = numsSize - 1; index >= 0; index--) {
        //��ָ��ָ��Ԫ�ص�ƽ��
        int lSquare = nums[left] * nums[left];
        //��ָ��ָ��Ԫ�ص�ƽ��
        int rSquare = nums[right] * nums[right];
        //����ָ��ָ��Ԫ��ƽ������ָ��ָ��Ԫ��ƽ���󣬽���ָ��ָ��Ԫ��ƽ�����������顣��ָ������һλ
        if(lSquare > rSquare) {
            ans[index] = lSquare;
            left++;
        } 
        //����ָ��ָ��Ԫ��ƽ������ָ��ָ��Ԫ��ƽ���󣬽���ָ��ָ��Ԫ��ƽ�����������顣��ָ������һλ
        else {
            ans[index] = rSquare;
            right--;
        }
    }
    //���ؽ������
    return ans;
}