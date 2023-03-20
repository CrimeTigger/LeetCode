#define max(a, b) (((a) > (b)) ? (a) : (b))

int *initCandyArr(int size) {
    int *candyArr = (int*)malloc(sizeof(int) * size);

    int i;
    for(i = 0; i < size; ++i)
        candyArr[i] = 1;

    return candyArr;
}

int candy(int* ratings, int ratingsSize){
    // 初始化数组，每个小孩开始至少有一颗糖
    int *candyArr = initCandyArr(ratingsSize);

    int i;
    // 先判断右边是否比左边评分高。若是，右边孩子的糖果为左边孩子+1（candyArr[i] = candyArr[i - 1] + 1)
    for(i = 1; i < ratingsSize; ++i) {
        if(ratings[i] > ratings[i - 1])
            candyArr[i] = candyArr[i - 1] + 1;
    }

    // 再判断左边评分是否比右边高。
    // 若是，左边孩子糖果为右边孩子糖果+1/自己所持糖果最大值。（若糖果已经比右孩子+1多，则不需要更多糖果）
    // 举例：ratings为[1, 2, 3, 1]。此时评分为3的孩子在判断右边比左边大后为3，虽然它比最末尾的1(ratings[3])大，但是candyArr[3]为1。所以不必更新candyArr[2]
    for(i = ratingsSize - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1])
            candyArr[i] = max(candyArr[i], candyArr[i + 1] + 1);
    }

    // 求出糖果之和
    int result = 0;
    for(i = 0; i < ratingsSize; ++i) {
        result += candyArr[i];
    }
    return result;
}