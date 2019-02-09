
#pragma once

#include "../Head.h"

namespace L0123
{


/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
        for (int p : prices)
        {
            b1 = (std::max)(b1, -p);
            s1 = (std::max)(s1, b1 + p);
            b2 = (std::max)(b2, s1 - p);
            s2 = (std::max)(s2, b2 + p);
        }

        return s2;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 3, 5, 0, 0, 3, 1, 4};
        Print(maxProfit(test));
    }
#endif /// DEBUG
};


}