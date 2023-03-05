#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int * window= (int*) malloc(sizeof(int) *numsSize);//����˫�˶���
    int * res=(int*) malloc(sizeof(int)*numsSize+1);
    int left=0;
    int right=0;
    int loc=0;
    for(int i=0; i<numsSize; i++){
        while(right>left && nums[i]>nums[window[right-1]]){//��Ҫ��֤ÿ�ηŽ�ȥ������Ҫ��ĩβ�Ķ��󣬷���Ҳ����
            right--;
        }
        window[right++]=i;//�����������
        if(i-window[left]>=k){//����ͷ�����Ҫ��[i - k + 1, i]��Χ�ڣ���������Ҫ����
            left++;
        }
        if(i>=k-1){
            res[loc++]=nums[window[left]];
        }
    }
    *returnSize = loc;
    return res;
}