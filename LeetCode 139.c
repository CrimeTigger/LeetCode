bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int sLen = strlen(s);
    bool dp[sLen + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;           /* 初始化，以便状态转移 */
    for (int i = 1; i <= sLen; i++) /* 从s的第一个字母开始枚举 */
    /* 枚举到第i个字母时，i之前的dp已经全部算出来了，我们再枚举字典中的单词，根据每个单词的
    长度决定分割点，假设分割点是k，当分割点后的子串能与字典单词匹配且dp[k]为true，则dp[i]为true
    */
        for (int j = 0; j < wordDictSize; j++) {  
            int len = strlen(wordDict[j]);
            int k = i - len;        /* 分割点是由i和字典单词长度决定的 */
            if (k < 0)
                continue;
            dp[i] = (dp[k] && !strncmp(s + k, wordDict[j], len)) || dp[i];
                                /* 这里注意要限制长度，故用strncmp */
                                /* 进一步追求速度可用哈希法等代替strncmp */
        }
    
  /* for (int i = 1; i <= sLen; i++)
        printf("%d ", dp[i]); */
    return dp[sLen];
}