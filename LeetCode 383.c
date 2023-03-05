bool canConstruct(char *ransomNote, char *magazine)
{
    int hash[26] = {0};
    int rsize = strlen(ransomNote);
    int msize = strlen(magazine);
    if (rsize > msize)
    {
        return false;
    }
    for (int i = 0; i < msize; i++)
    {
        hash[magazine[i] - 'a']++;
    }
    for (int i = 0; i < rsize; i++)
    {
        hash[ransomNote[i] - 'a']--;
        if (hash[ransomNote[i] - 'a'] < 0)
        {
            return false;
        }
    }
    return true;
}



