
#pragma once

#include "../Head.h"

namespace L0334
{


/// https://leetcode.com/problems/increasing-triplet-subsequence/
class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        const int count = 3;
        vector<int> mins(count - 1, INT_MAX);
        for (int num : nums)
        {
            bool is_find = false;
            for (int i = 0; i < count - 1; ++i)
            {
                if (num <= mins[i])
                {
                    mins[i] = num;
                    is_find = true;
                    break;
                }
            }

            if (!is_find)
            {
                return true;
            }
        }

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 3, -4, -5};
        Print(increasingTriplet(test));
    }
#endif /// DEBUG
};


}