int removeElement(int* nums, int numsSize, int val){
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++) {
        //����ָ��λ�õ�Ԫ�ز�����Ҫɾ����Ԫ��
        if(nums[fast] != val) {
            //����Ų����ָ��ָ���λ�ã���ָ��+1
            nums[slow++] = nums[fast];
        }
    }
    //�����ָ��Ĵ�С�����µ�����Ĵ�С
    return slow;
}