bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int sLen = strlen(s);
    bool dp[sLen + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;           /* ��ʼ�����Ա�״̬ת�� */
    for (int i = 1; i <= sLen; i++) /* ��s�ĵ�һ����ĸ��ʼö�� */
    /* ö�ٵ���i����ĸʱ��i֮ǰ��dp�Ѿ�ȫ��������ˣ�������ö���ֵ��еĵ��ʣ�����ÿ�����ʵ�
    ���Ⱦ����ָ�㣬����ָ����k�����ָ�����Ӵ������ֵ䵥��ƥ����dp[k]Ϊtrue����dp[i]Ϊtrue
    */
        for (int j = 0; j < wordDictSize; j++) {  
            int len = strlen(wordDict[j]);
            int k = i - len;        /* �ָ������i���ֵ䵥�ʳ��Ⱦ����� */
            if (k < 0)
                continue;
            dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], len)) || dp[i];
                                /* ����ע��Ҫ���Ƴ��ȣ�����strncmp */
                                /* ��һ��׷���ٶȿ��ù�ϣ���ȴ���strncmp */
        }
    
  /* for (int i = 1; i <= sLen; i++)
        printf("%d ", dp[i]); */
    return dp[sLen];
}