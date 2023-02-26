int minSubArrayLen(int target, int* nums, int numsSize){
    //初始化最小长度为INT_MAX
    int minLength = INT_MAX;
    int sum = 0;

    int left = 0, right = 0;
    //右边界向右扩展
    for(; right < numsSize; ++right) {
        sum += nums[right];
        //当sum的值大于等于target时，保存长度，并且收缩左边界
        while(sum >= target) {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }
    //若minLength不为INT_MAX，则返回minLnegth
    return minLength == INT_MAX ? 0 : minLength;
}