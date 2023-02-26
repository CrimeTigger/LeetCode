int minSubArrayLen(int target, int* nums, int numsSize){
    //��ʼ����С����ΪINT_MAX
    int minLength = INT_MAX;
    int sum = 0;

    int left = 0, right = 0;
    //�ұ߽�������չ
    for(; right < numsSize; ++right) {
        sum += nums[right];
        //��sum��ֵ���ڵ���targetʱ�����泤�ȣ�����������߽�
        while(sum >= target) {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }
    //��minLength��ΪINT_MAX���򷵻�minLnegth
    return minLength == INT_MAX ? 0 : minLength;
}