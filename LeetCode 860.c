bool lemonadeChange(int *bills, int billsSize)
{
    // 分别记录五元、十元的数量（二十元不用记录，因为不会用到20元找零）
    int fiveCount = 0;
    int tenCount = 0;

    int i;
    for (i = 0; i < billsSize; ++i)
    {
        // 分情况讨论每位顾客的付款
        switch (bills[i])
        {
        // 情况一：直接收款五元
        case 5:
            fiveCount++;
            break;
        // 情况二：收款十元
        case 10:
            // 若没有五元找零，返回false
            if (fiveCount == 0)
                return false;
            // 收款十元并找零五元
            fiveCount--;
            tenCount++;
            break;
        // 情况三：收款二十元
        case 20:
            // 若可以，优先用十元和五元找零（因为十元只能找零20，所以需要尽量用掉。而5元能找零十元和二十元）
            if (fiveCount > 0 && tenCount > 0)
            {
                fiveCount--;
                tenCount--;
            }
            // 若没有十元，但是有三张五元。用三张五元找零
            else if (fiveCount >= 3)
                fiveCount -= 3;
            // 无法找开，返回false
            else
                return false;
            break;
        }
    }
    // 全部可以找开，返回true
    return true;
}