
#pragma once

#include "../Head.h"

namespace L0132
{


/// https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution
{
public:
    int minCut(string s)
    {
        const int Length = s.size();
        vector<int> dp(Length + 1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= Length; i++)
        {
            dp[i] = i - 1;
        }

        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; i - j >= 0 && i + j < Length && s[i - j] == s[i + j]; ++j) // odd length palindrome
            {
                dp[i + j + 1] = (std::min)(dp[i + j + 1], 1 + dp[i - j]);
            }

            for (int j = 1; i - j + 1 >= 0 && i + j < Length && s[i - j + 1] == s[i + j]; ++j) // even length palindrome
            {
                dp[i + j + 1] = (std::min)(dp[i + j + 1], 1 + dp[i - j + 1]);
            }
        }
        return dp[Length];
    }

#ifdef DEBUG
    void Test()
    {
        Print(minCut("apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp"));
    }
#endif /// DEBUG
};


}