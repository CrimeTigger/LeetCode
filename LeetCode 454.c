struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

int fourSumCount(int *A, int ASize, int *B, int BSize, int *C, int CSize, int *D, int DSize)
{
    struct hashTable *hashtable = NULL;
    for (int i = 0; i < ASize; ++i)
    {
        for (int j = 0; j < BSize; ++j)
        {
            int ikey = A[i] + B[j];
            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if (tmp == NULL)
            {
                struct hashTable *tmp = malloc(sizeof(struct hashTable));
                tmp->key = ikey, tmp->val = 1;
                HASH_ADD_INT(hashtable, key, tmp);
            }
            else
            {
                tmp->val++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < CSize; ++i)
    {
        for (int j = 0; j < DSize; ++j)
        {
            int ikey = -C[i] - D[j];
            struct hashTable *tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if (tmp != NULL)
            {
                ans += tmp->val;
            }
        }
    }
    return ans;
}