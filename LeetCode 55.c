// ��ô��������ת��Ϊ��Ծ���Ƿ�Χ�����ɲ����Ը��ǵ��յ㣡
// ̰���㷨�ֲ����Ž⣺ÿ��ȡ�����Ծ������ȡ��󸲸Ƿ�Χ�����������Ž⣺���õ�������󸲸Ƿ�Χ�����Ƿ��ܵ��յ㡣
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool canJump(int *nums, int numsSize)
{
    int cover = 0;

    int i;
    // ֻ���ܻ�ȡcover��Χ�еĲ���������i<=cover
    for (i = 0; i <= cover; ++i)
    {
        // ����coverΪ��i�����ܵ�������ֵ/cover��ֵ�нϴ�ֵ
        cover = max(i + nums[i], cover);

        // �����º�cover���Ե�������Ԫ�أ�����true
        if (cover >= numsSize - 1)
            return true;
    }

    return false;
}