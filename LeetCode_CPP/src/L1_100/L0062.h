#pragma once

#include "../Head.h"

namespace L0062
{


/// https://leetcode.com/problems/unique-paths/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        //if (1 > m || 1 > n) return 0;
        /// L = (m - 1) + (n - 1)
        /// C(L, max((m - 1),(m - 1)))
        if (1 == m || 1 == n) return 1;
        int L = (--m) + (--n);
        long ret = 1L;
        long div = 1L;
        int max_num = std::max(m, n);
        for (int i = L; i > max_num; --i)
        {
            ret *= i;
            div *= (i - max_num);
        }

        return static_cast<int>(ret / div);
    }

#ifdef DEBUG
    void Test()
    {
        Print(uniquePaths(23, 12));
    }
#endif /// DEBUG
};


}