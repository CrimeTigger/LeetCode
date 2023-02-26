// (�汾һ) ����ұ����� [left, right]
int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize-1;
    int middle = 0;
    //��leftС�ڵ���right��˵��������Ԫ�ز�Ϊ0
    while(left<=right) {
        //���²����±�middle��ֵ
        middle = (left+right)/2;
        //��ʱtarget���ܻ���[left,middle-1]������
        if(nums[middle] > target) {
            right = middle-1;
        } 
        //��ʱtarget���ܻ���[middle+1,right]������
        else if(nums[middle] < target) {
            left = middle+1;
        } 
        //��ǰ�±�Ԫ�ص���targetֵʱ������middle
        else if(nums[middle] == target){
            return middle;
        }
    }
    //��δ�ҵ�targetԪ�أ�����-1
    return -1;
}