#pragma once

#include "../Head.h"

namespace L0050
{
    /// https://leetcode.com/problems/powx-n/
    class Solution
    {
    public:
        double myPow(double x, int n)
        {
            if (n < 0) return myPow(1.0 / x, -n);
            else if (0 == n) return 1.0;
            else
            {
                if (n % 2 == 0) return myPow(x * x, n / 2);
                else return myPow(x * x, (n - 1) / 2) * x;
            }
        }

    #ifdef DEBUG
        void Test()
        {
            Print(myPow(2.10000, 3));
        }
    #endif /// DEBUG
    };
}