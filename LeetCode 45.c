// Ҫ�Ӹ��Ƿ�Χ������������ô�������Ƿ�Χ��һ���ǿ��������ģ�����С�Ĳ������Ӹ��Ƿ�Χ�����Ƿ�Χһ���������յ㣬�õ��ľ�����С������
// ������Ҫͳ���������Ƿ�Χ����ǰ��һ������󸲸Ǻ���һ����󸲸�

// �汾һ

int jump(int *nums, int numsSize)
{
    if (numsSize == 1)
        return 0;
    int curDistance = 0;  // ��ǰ������Զ�����±�
    int count = 0;        // ��¼�ߵ������
    int nextDistance = 0; // ��һ��������Զ�����±�
    for (int i = 0; i < numsSize; i++)
    {
        nextDistance = fmax(nums[i] + i, nextDistance);
        if (i == curDistance)
        { // ������ǰ������Զ�����±�
            if (curDistance < numsSize - 1)
            {                               // �����ǰ������Զ�����±겻���յ�
                count++;                    // ��Ҫ����һ��
                curDistance = nextDistance; // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                if (nextDistance >= numsSize - 1)
                    break; // ��һ���ĸ��Ƿ�Χ�Ѿ����Դﵽ�յ㣬����ѭ��
            }
            else
                break; // ��ǰ������Զ�ൽ�Ｏ���յ㣬������count++�����ˣ�ֱ�ӽ���
        }
    }
    return count;
}

// �侫�����ڿ����ƶ��±�iֻ�ƶ���nums.size() - 2��λ�ã������ƶ��±�ֻҪ������ǰ������Զ������±ֱ꣬�Ӳ�����һ�����ÿ��Ǳ����
int jump(int *nums, int numsSize)
{
    int curDistance = 0;  // ��ǰ���ǵ���Զ�����±�
    int ans = 0;          // ��¼�ߵ������
    int nextDistance = 0; // ��һ�����ǵ���Զ�����±�
    for (int i = 0; i < numsSize - 1; i++)
    {                                                   // ע��������С��nums.size() - 1�����ǹؼ�����
        nextDistance = fmax(nums[i] + i, nextDistance); // ������һ�����ǵ���Զ�����±�
        if (i == curDistance)
        {                               // ������ǰ���ǵ���Զ�����±�
            curDistance = nextDistance; // ���µ�ǰ���ǵ���Զ�����±�
            ans++;
        }
    }
    return ans;
}