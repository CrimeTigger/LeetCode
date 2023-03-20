#define max(a, b) (((a) > (b)) ? (a) : (b))

int *initCandyArr(int size) {
    int *candyArr = (int*)malloc(sizeof(int) * size);

    int i;
    for(i = 0; i < size; ++i)
        candyArr[i] = 1;

    return candyArr;
}

int candy(int* ratings, int ratingsSize){
    // ��ʼ�����飬ÿ��С����ʼ������һ����
    int *candyArr = initCandyArr(ratingsSize);

    int i;
    // ���ж��ұ��Ƿ��������ָߡ����ǣ��ұߺ��ӵ��ǹ�Ϊ��ߺ���+1��candyArr[i] = candyArr[i - 1] + 1)
    for(i = 1; i < ratingsSize; ++i) {
        if(ratings[i] > ratings[i - 1])
            candyArr[i] = candyArr[i - 1] + 1;
    }

    // ���ж���������Ƿ���ұ߸ߡ�
    // ���ǣ���ߺ����ǹ�Ϊ�ұߺ����ǹ�+1/�Լ������ǹ����ֵ�������ǹ��Ѿ����Һ���+1�࣬����Ҫ�����ǹ���
    // ������ratingsΪ[1, 2, 3, 1]����ʱ����Ϊ3�ĺ������ж��ұ߱���ߴ��Ϊ3����Ȼ������ĩβ��1(ratings[3])�󣬵���candyArr[3]Ϊ1�����Բ��ظ���candyArr[2]
    for(i = ratingsSize - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1])
            candyArr[i] = max(candyArr[i], candyArr[i + 1] + 1);
    }

    // ����ǹ�֮��
    int result = 0;
    for(i = 0; i < ratingsSize; ++i) {
        result += candyArr[i];
    }
    return result;
}