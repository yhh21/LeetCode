#pragma once

#include "Head.h"

class Solution
{
public:
    static int lengthOfLastWord(string s) {
        int Length = s.length();
        int res = 0;
        bool isFind = false;

        for (int i = Length - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++res;
                isFind = true;
            }
            else if (isFind) break;
        }

        return res;
    }
};