
#pragma once

#include "../Head.h"

namespace L0165
{


/// https://leetcode.com/problems/compare-version-numbers/
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        const int Length1 = version1.size();
        const int Length2 = version2.size();

        for (int i = 0, j = 0; i < Length1 || j < Length2; ++i, ++j)
        {
            int v1 = 0, v2 = 0;
            for (;i < Length1 && version1[i] != '.';)
            {
                v1 = v1 * 10 + version1[i] - '0';
                ++i;
            }

            for (; j < Length2 && version2[j] != '.';)
            {
                v2 = v2 * 10 + version2[j] - '0';
                ++j;
            }

            if (v1 > v2)
            {
                return 1;
            }
            else if (v1 < v2)
            {
                return -1;
            }
        }

        return 0;
    }

#ifdef DEBUG
    void Test()
    {
        Print(compareVersion("0.1", "1.1"));
    }
#endif /// DEBUG
};


}