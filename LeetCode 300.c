int lengthOfLIS(int* nums, int numsSize){
    if(numsSize<1) return 0;
    int dp[numsSize];
    memset(dp,1,sizeof(dp));
    int result=0;
    for(int i=1;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]) dp[i]=fmax(dp[i],dp[j]+1);
        }
        result=fmax(dp[i],result);
    }
    return result;
}