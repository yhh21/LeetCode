
#pragma once

#include "../Head.h"

namespace L0238
{


/// https://leetcode.com/problems/product-of-array-except-self/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        const int Length = nums.size();
        vector<int> ret(Length);
        ret[0] = 1;

        for (int i = 1; i < Length; ++i)
        {
            ret[i] = ret[i - 1] * nums[i - 1];
        }

        int tmp = 1;
        for (int i = Length -1; i >= 0; --i)
        {
            ret[i] *= tmp;
            tmp *= nums[i];
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3, 4};
        Print(productExceptSelf(test));
    }
#endif /// DEBUG
};


}