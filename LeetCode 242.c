bool isAnagram(char *s, char *t)
{
    int *record[26] = {0};
    int n = strlen(s);
    int l = strlen(t);
    for (int i = 0; i < n; i++)
    {
        record[s[i] - 'a']++;
    }
    for (int i = 0; i < l; i++)
    {
        // record[t[i]-'a']--;
        record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (record[i] != 0)
        {
            return false;
        }
    }
    return true;
}