int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    //��ʼ�����صĽ������Ĵ�С
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //��ʼ�����ؽ������ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    //����ÿ��ѭ������ʼλ��
    int startX = 0;
    int startY = 0;
    //���ö�ά������м�ֵ����nΪ��������Ҫ������м���������
    int mid = n / 2;
    //ѭ��Ȧ��
    int loop = n / 2;
    //ƫ����
    int offset = 1;
    //��ǰҪ��ӵ�Ԫ��
    int count = 1;

    while(loop) {
        int i = startX;
        int j = startY;
        //ģ���ϲ������
        for(; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //ģ���Ҳ���ϵ���
        for(; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //ģ���²���ҵ���
        for(; j > startY; j--) {
            ans[i][j] = count++;
        }
        //ģ�������µ���
        for(; i > startX; i--) {
            ans[i][j] = count++;
        }6
        //ƫ��ֵÿ�μ�2
        offset+=2;
        //������ʼλ��ÿ��+1
        startX++;
        startY++;
        loop--;
    }
    //��nΪ������Ҫ�����������м丳ֵ
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}