#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int * window= (int*) malloc(sizeof(int) *numsSize);//创建双端队列
    int * res=(int*) malloc(sizeof(int)*numsSize+1);
    int left=0;
    int right=0;
    int loc=0;
    for(int i=0; i<numsSize; i++){
        while(right>left && nums[i]>nums[window[right-1]]){//就要保证每次放进去的数字要比末尾的都大，否则也弹出
            right--;
        }
        window[right++]=i;//队列添加索引
        if(i-window[left]>=k){//队列头结点需要在[i - k + 1, i]范围内，不符合则要弹出
            left++;
        }
        if(i>=k-1){
            res[loc++]=nums[window[left]];
        }
    }
    *returnSize = loc;
    return res;
}