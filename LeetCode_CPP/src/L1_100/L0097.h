
#pragma once

#include "../Head.h"

namespace L0097
{


/// https://leetcode.com/problems/unique-binary-search-trees/
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        const int Length1 = s1.length();
        const int Length2 = s2.length();
        const int Length3 = s3.length();

        if (Length3 != Length1 + Length2)
        {
            return false;
        }

        bool dp[Length1 + 1][Length2 + 1];

        for (int i = 0; i < Length1 + 1; ++i)
        {
            for (int j = 0; j < Length2 + 1; ++j)
            {
                if (0 == i && 0 == j)
                {
                    dp[i][j] = true;
                }
                else if (0 == i)
                {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
                else if (0 == j)
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                        || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[Length1][Length2];
    }

#ifdef DEBUG
    void Test()
    {
        Print(isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    }
#endif /// DEBUG
};


}