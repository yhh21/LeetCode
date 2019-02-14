
#pragma once

#include "../Head.h"

namespace L0139
{


/// https://leetcode.com/problems/word-break/
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> m_set;
        for (string str : wordDict)
        {
            m_set.insert(str);
        }

        const int Length = s.size();
        vector<bool> dp(Length + 1, false);
        dp[0] = true;

        for (int i = 1; i <= Length; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (dp[j])
                {
                    if (m_set.find(s.substr(j, i - j)) != m_set.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[Length];
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test = {"leet", "code"};
        Print(wordBreak("leetcode", test));
    }
#endif /// DEBUG
};


}