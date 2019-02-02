
#pragma once

#include "../Head.h"

namespace L0091
{


/// https://leetcode.com/problems/decode-ways/
class Solution
{
public:
    int numDecodings(string s)
    {
        const int Length = s.size();
        if (0 == Length || '0' == s[0])
        {
            return 0;
        }

        vector<int> dp(Length + 1, 1);

        for (int i = 2; i < Length + 1; ++i)
        {
            dp[i] = ('0' != s[i - 1] ? dp[i - 1] : 0)
                + ('0' != s[i - 2] && (s[i - 2] < '2' || ('2' == s[i - 2] && s[i - 1] <= '6')) ? dp[i - 2] : 0);
        }

        return dp[Length];
    }

#ifdef DEBUG
    void Test()
    {
        Print(numDecodings("1001"));
    }
#endif /// DEBUG
};


}