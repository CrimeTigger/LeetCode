int* intersection1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int nums1Cnt[1000] = {0};
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int * result = (int *) calloc(lessSize, sizeof(int));
    int resultIndex = 0;
    int* tempNums;
    
    int i;

    /* Calculate the number's counts for nums1 array */
    for(i = 0; i < nums1Size; i ++) {
        nums1Cnt[nums1[i]]++;
    }

    /* Check if the value in nums2 is existing in nums1 count array */
    for(i = 0; i < nums2Size; i ++) {
        if(nums1Cnt[nums2[i]] > 0) {
            result[resultIndex] = nums2[i];
            resultIndex ++;
            /* Clear this count to avoid duplicated value */
            nums1Cnt[nums2[i]] = 0;
        }
    }
    * returnSize = resultIndex;
    return result;
}