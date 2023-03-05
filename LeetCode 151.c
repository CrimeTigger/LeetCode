char * reverseWords(char * s){
    int i = 0, n = strlen(s), top = 0;
    while(i < n && s[i] == ' ') ++i;
    while(i < n){
        while(i < n && isalnum(s[i])) s[top++] = s[i++];
        s[top++] = '\0';
        while(i < n && !isalnum(s[i])) ++i;
    }
    s[--top] = '\0';
    char *res = calloc(n + 2, sizeof(char));
    int j = top - 1;
    while(j >= 0){
        while(j >= 0 && isalnum(s[j])) --j;
        strcat(res, s + j + 1);
        strcat(res, " ");
        --j;
    }
    res[strlen(res) - 1] = 0;
    return res;
}