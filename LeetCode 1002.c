//若两个哈希表定义为char数组（每个单词的最大长度不会超过100，因此可以用char表示），可以提高时间和空间效率
void updateHashTable(int* hashTableOne, int* hashTableTwo) {
    int i;
    for(i = 0; i < 26; i++) {
        hashTableOne[i] = hashTableOne[i] < hashTableTwo[i] ? hashTableOne[i] : hashTableTwo[i];
    }
}

char ** commonChars(char ** words, int wordsSize, int* returnSize){
    //用来统计所有字母出现的最小频率
    int hashTable[26] = { 0 };
    //初始化返回的char**数组以及返回数组长度
    *returnSize = 0;
    char** ret = (char**)malloc(sizeof(char*) * 100);

    //如果输入数组长度为0，则返回NULL
    if(!wordsSize) 
        return NULL;

    int i;
    //更新第一个单词的字母频率
    for(i = 0; i < strlen(words[0]); i++)
        hashTable[words[0][i] - 'a']++;
    //更新从第二个单词开始的字母频率
    for(i = 1; i < wordsSize; i++) {
        //创建新的哈希表，记录新的单词的字母频率
        int newHashTable[26] = { 0 };
        int j;
        for(j = 0; j < strlen(words[i]); j++) {
            newHashTable[words[i][j] - 'a']++;
        }
        //更新原哈希表
        updateHashTable(hashTable, newHashTable);
    }

    //将哈希表中的字符变为字符串放入ret中
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