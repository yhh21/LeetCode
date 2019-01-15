#pragma once

#include "../Head.h"

namespace L0076
{


/// https://leetcode.com/problems/minimum-window-substring/
class Solution
{
public:
    string minWindow(string s, string t)
    {
        const int s_Length = s.size();
        const int t_Length = t.size();
        if (0 == s_Length || 0 == t_Length || s_Length < t_Length)  return "";

        vector<int> map(128, 0);
        for (int i = 0; i < t_Length; ++i)
        {
            ++map[t[i]];
        }

        int head = 0, distance = s_Length + 1;
        for (int left = 0, right = 0, count = t_Length; right < s_Length;)
        {
            if (0 < map[s[right++]]--)
            {
                --count;
            }

            for (; 0 == count; ++left)
            {
                if (0 == map[s[left]]++)
                {
                    if (right - left < distance)
                    {
                        distance = right - left;
                        head = left;
                    }

                    ++count;
                }
            }
        }

        return distance <= s_Length ? s.substr(head, distance) : "";
    }

#ifdef DEBUG
    void Test()
    {
        Print(minWindow("ADOBECODEBANC", "ABC"));
    }
#endif /// DEBUG
};


}