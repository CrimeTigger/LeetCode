//��������ϣ����Ϊchar���飨ÿ�����ʵ���󳤶Ȳ��ᳬ��100����˿�����char��ʾ�����������ʱ��Ϳռ�Ч��
void updateHashTable(int* hashTableOne, int* hashTableTwo) {
    int i;
    for(i = 0; i < 26; i++) {
        hashTableOne[i] = hashTableOne[i] < hashTableTwo[i] ? hashTableOne[i] : hashTableTwo[i];
    }
}

char ** commonChars(char ** words, int wordsSize, int* returnSize){
    //����ͳ��������ĸ���ֵ���СƵ��
    int hashTable[26] = { 0 };
    //��ʼ�����ص�char**�����Լ��������鳤��
    *returnSize = 0;
    char** ret = (char**)malloc(sizeof(char*) * 100);

    //����������鳤��Ϊ0���򷵻�NULL
    if(!wordsSize) 
        return NULL;

    int i;
    //���µ�һ�����ʵ���ĸƵ��
    for(i = 0; i < strlen(words[0]); i++)
        hashTable[words[0][i] - 'a']++;
    //���´ӵڶ������ʿ�ʼ����ĸƵ��
    for(i = 1; i < wordsSize; i++) {
        //�����µĹ�ϣ����¼�µĵ��ʵ���ĸƵ��
        int newHashTable[26] = { 0 };
        int j;
        for(j = 0; j < strlen(words[i]); j++) {
            newHashTable[words[i][j] - 'a']++;
        }
        //����ԭ��ϣ��
        updateHashTable(hashTable, newHashTable);
    }

    //����ϣ���е��ַ���Ϊ�ַ�������ret��
    for(i = 0; i < 26; i++) {
        if(hashTable[i]) {
            int j;
            for(j = 0; j < hashTable[i]; j++) {
                char* tempString = (char*)malloc(sizeof(char) * 2);
                tempString[0] = i + 'a';
                tempString[1] = '\0';
                ret[(*returnSize)++] = tempString;
            }
        }
    }
    return ret;
}