
#pragma once

#include "../Head.h"

namespace L0087
{


/// https://leetcode.com/problems/scramble-string/
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        return IsScramble(s1, 0, s1.size(), s2, 0, s2.size());

        /// 可以改成更高效的DP
    }

    bool IsScramble(const string &s1, int start1, int end1, const string &s2, int start2, int end2)
    {
        const int Length = end1 - start1;
        if (Length != end2 - start2)
        {
            return false;
        }
        else
        {
            bool is_equal = true;
            for (int i = 0; i < Length; ++i)
            {
                if (s1.at(start1 + i) != s2.at(start2 + i))
                {
                    is_equal = false;
                    break;
                }
            }

            if (is_equal)
            {
                return true;
            }
        }

        vector<char> count(26, 0);
        for (int i = 0; i < Length; ++i)
        {
            ++count[s1[start1 + i] - 'a'];
            --count[s2[start2 + i] - 'a'];
        }

        for (int i = 0; i < 26; i++)
        {
            if (0 != count[i])
            {
                return false;
            }
        }

        for (int i = 1; i < Length; ++i)
        {
            if ((IsScramble(s1, start1, start1 + i, s2, start2, start2 + i)
                && IsScramble(s1, start1 + i, end1, s2, start2 + i, end2))
                || (IsScramble(s1, start1, start1 + i, s2, start2 + Length - i, end2)
                    && IsScramble(s1, start1 + i, end1, s2, start2, start2 + Length - i)))
            {
                return true;
            }
        }

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        Print(isScramble("great", "rgeat"));
    }
#endif /// DEBUG
};


}