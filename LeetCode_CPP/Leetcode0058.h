#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0058
{
public:
    static int lengthOfLastWord(string s) {
        int res = 0;
        int Length = s.length();
        bool isFind = false;

        for (int i = Length - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++res;
                isFind = true;
            }
            else if (isFind) {
                break;
            }
        }

        return res;
    }
};