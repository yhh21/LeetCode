
#pragma once

#include "../Head.h"

namespace L0151
{


/// https://leetcode.com/problems/reverse-words-in-a-string/
class Solution
{
public:
    void reverseWords(string &s)
    {
        const int Length = s.size();

        int j = 0;
        for (int i = 0; i < Length; ++i)
        {
            if (' ' == s[i])
            {
                continue;
            }

            if (i < Length && j > 0)
            {
                s[j++] = ' ';
            }

            int start = j;
            for (; i < Length && s[i] != ' ';)
            {
                s[j++] = s[i++];
            }

            ReverseWord(s, start, j - 1);
        }

        s.resize(j);
        ReverseWord(s, 0, j - 1);
    }

    void ReverseWord(string &s, int start, int end)
    {
        for (; start < end; ++start, --end)
        {
            std::swap(s[start], s[end]);
        }
    }

#ifdef DEBUG
    void Test()
    {
        string str = " the sky is blue";
        reverseWords(str);
        Print(str);
    }
#endif /// DEBUG
};


}