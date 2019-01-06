#pragma once

#include "../Head.h"

namespace L0044
{
    /// https://leetcode.com/problems/wildcard-matching/
    class Solution
    {
    public:
        bool isMatch(string s, string p)
        {
            const int s_Length = s.size();
            const int p_Length = p.size();

            if (0 == p_Length) return 0 == s_Length;

            vector<vector<bool>> dp;
            dp.resize(s_Length + 1);
            for (int i = 0; i <= s_Length; ++i)
            {
                dp[i].resize(p_Length + 1);
            }

            dp[0][0] = true;
            dp[0][1] = ('*' == p[0]);

            for (int i = 1; i <= s_Length; ++i)
            {
                dp[i][0] = false;
            }

            for (int j = 1; j <= p_Length; ++j)
            {
                dp[0][j] = dp[0][j - 1] && ('*' == p[j - 1]);
            }

            for (int j = 1; j <= p_Length; ++j)
            {
                for (int i = 1; i <= s_Length; ++i)
                {
                    if ('*' != p[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] && ('?' == p[j - 1] || s[i - 1] == p[j - 1]);
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    }
                }
            }

            return dp[s_Length][p_Length];
        }

    #ifdef DEBUG
        void Test()
        {
            isMatch("aa", "*");
        }
    #endif /// DEBUG
    };
}