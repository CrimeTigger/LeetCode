char * reverseStr(char * s, int k){
    int len = strlen(s);

    for (int i = 0; i < len; i += (2 * k)) {
        //ÅÐ¶ÏÊ£Óà×Ö·ûÊÇ·ñÉÙÓÚ k
        k = i + k > len ? len - i : k;

        int left = i;
        int right = i + k - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    return s;
}