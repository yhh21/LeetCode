
#pragma once

#include "../Head.h"

namespace L0065
{


/// https://leetcode.com/problems/valid-number/
class Solution
{
public:
    bool isNumber(string s)
    {
        const int Length = s.size();
        if (0 == Length)
        {
            return false;
        }

        int i = 0;
        for (; i < Length && ' ' == s[i]; ++i);

        if (i < Length && ('+' == s[i] || '-' == s[i]))
        {
            ++i;
        }

        int count_point = 0, count_num = 0;
        for (;i < Length && ((s[i] >= '0' && s[i] <= '9') || '.' == s[i]); ++i)
        {
            s[i] == '.' ? ++count_point : ++count_num;
        }
        if (count_point > 1 || count_num < 1)
        {
            return false;
        }

        if (i < Length && 'e' == s[i])
        {
            ++i;
            if (i < Length && ('+' == s[i] || '-' == s[i]))
            {
                ++i;
            }

            int count_e = 0;
            for (;i < Length && (s[i] >= '0' && s[i] <= '9'); ++i)
            {
                ++count_e;
            }
            if (count_e < 1)
            {
                return false;
            }
        }

        for (; i < Length && s[i] == ' '; ++i);

        return i == Length;
    }
};


}