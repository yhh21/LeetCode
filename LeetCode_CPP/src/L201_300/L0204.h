
#pragma once

#include "../Head.h"

namespace L0204
{


/// https://leetcode.com/problems/count-primes/
class Solution
{
public:
    int countPrimes(int n)
    {
        bool *not_primes = new bool[n]();

        int ret = 0;
        for (int i = 2; i < n; ++i)
        {
            if (!not_primes[i])
            {
                ++ret;
                for (int j = 1; j * i < n; ++j)
                {
                    not_primes[j * i] = true;
                }
            }
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        Print(countPrimes(10));
    }
#endif /// DEBUG
};


}