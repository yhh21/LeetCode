
#pragma once

#include "../Head.h"

namespace L0191
{


/// https://leetcode.com/problems/number-of-1-bits/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (; n != 0; n = n & (n - 1))
        {
            ++count;
        }

        return count;
    }

#ifdef DEBUG
    void Test()
    {
        Print(hammingWeight(0xff00ff00));
    }
#endif /// DEBUG
};


}