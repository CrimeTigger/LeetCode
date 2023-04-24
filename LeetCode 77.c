int* path;
int pathTop;
int** ans;
int ansTop;

void backtracking(int n, int k,int startIndex) {
    //��path��Ԫ�ظ���Ϊk��ʱ��������Ҫ��path�������ans��ά������
    if(pathTop == k) {
        //path����Ϊ���Ƕ�̬���룬��ֱ�ӽ����ַ�����ά���飬path�����е�ֵ���������ǻ��ݶ��𽥱仯
        //��˴����µ�����洢path�е�ֵ
        int* temp = (int*)malloc(sizeof(int) * k);
        int i;
        for(i = 0; i < k; i++) {
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return ;
    }

    int j;
    for(j = startIndex; j <= n- (k - pathTop) + 1;j++) {
        //����ǰ������path����
        path[pathTop++] = j;
        //���еݹ�
        backtracking(n, k, j + 1);
        //���л��ݣ����������ϲ��㵯��
        pathTop--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    //path����洢���������Ľ��
    path = (int*)malloc(sizeof(int) * k);
    //ans��ά����洢���������Ľ������ļ��ϡ��������㹻�󣬱��⼫�������
    ans = (int**)malloc(sizeof(int*) * 10000);
    pathTop = ansTop = 0;

    //�����㷨
    backtracking(n, k, 1);
    //���ķ��ش�СΪans�����С
    *returnSize = ansTop;
    //returnColumnSizes����洢ans��ά�����Ӧ�±���һά����ĳ��ȣ���Ϊk��
    *returnColumnSizes = (int*)malloc(sizeof(int) *(*returnSize));
    int i;
    for(i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    //����ans��ά����
    return ans;
}