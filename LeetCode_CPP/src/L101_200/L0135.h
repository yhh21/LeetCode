
#pragma once

#include "../Head.h"

namespace L0135
{


/// https://leetcode.com/problems/candy/
class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        const int Length = ratings.size();
        vector<int> num(Length, 1);

        for (int i = 1; i < Length; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                num[i] = num[i - 1] + 1;
            }
        }

        for (int i = Length - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
            {
                num[i - 1] = (std::max)(num[i - 1], num[i] + 1);
            }
        }

        int ret = 0;
        for (int i = 0; i < Length; ++i)
        {
            ret += num[i];
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 0, 2};
        Print(candy(test));
    }
#endif /// DEBUG
};


}