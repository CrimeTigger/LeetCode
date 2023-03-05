//qsort����cmp����
int cmp(const void* ptr1, const void* ptr2) {
    return *((int*)ptr1) > *((int*)ptr2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    //����ans����ռ�
    int **ans = (int**)malloc(sizeof(int*) * 18000);
    int ansTop = 0;
    //������nums�����СС��3������Ҫ���������СΪ0
    if(numsSize < 3) {
        *returnSize = 0;
        return ans;
    }
    //��nums�����������
    qsort(nums, numsSize, sizeof(int), cmp);
    

    int i;
    //��forѭ���������飬��������Ϊi < numsSize - 2(��ΪҪԤ������ָ���λ��)
    for(i = 0; i < numsSize - 2; i++) {
        //����ǰiָ��Ԫ��>0�������left��right�Լ�i�ĺʹ���0��ֱ��break
        if(nums[i] > 0)
            break;
        //ȥ�أ�i > 0 && nums[i] == nums[i-1]
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        //������ָ�����ָ��
        int left = i + 1;
        int right = numsSize - 1;
        //����ָ�����ָ���ʱ����ѭ��
        while(right > left) {
            //�������֮��
            int sum = nums[right] + nums[left] + nums[i];
            //����С��0������ָ��+1����Ϊ��ָ���ұߵ����ȵ�ǰ��ָԪ�ش�
            if(sum < 0)
                left++;
            //���ʹ���0������ָ��-1
            else if(sum > 0)
                right--;
            //���͵���0
            else {
                //����һ����СΪ3������ռ䣬����nums[i], nums[left]��nums[right]
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];
                //�������������ans��
                ans[ansTop++] = arr;
                //ȥ��
                while(right > left && nums[right] == nums[right - 1])
                    right--;
                while(left < right && nums[left] == nums[left + 1])
                    left++;
                //��������ָ��
                left++;
                right--;
            }
        }
    }

    //�趨���ص������С
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int z;
    for(z = 0; z < ansTop; z++) {
        (*returnColumnSizes)[z] = 3;
    }
    return ans;
}