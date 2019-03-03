
#pragma once

#include "../Head.h"

namespace L0227
{


/// https://leetcode.com/problems/basic-calculator-ii/
class Solution
{
public:
    int calculate(string s)
    {
        int ret = 0, tmp = 0;
        char op = '+';
        const int Length = s.size();
        for (int i = 0; i < Length; )
        {
            if (' ' == s[i])
            {
                ++i;
                continue;
            }

            if (isdigit(s[i]))
            {
                int _tmp = s[i] - '0';
                while (++i < Length && isdigit(s[i]))
                {
                    _tmp = _tmp * 10 + (s[i] - '0');
                }
                switch (op)
                {
                case '+': tmp += _tmp; break;
                case '-': tmp -= _tmp; break;
                case '*': tmp *= _tmp; break;
                case '/': tmp /= _tmp; break;
                }
            }
            else
            {
                if (s[i] == '+' || s[i] == '-')
                {
                    ret += tmp;
                    tmp = 0;
                }
                op = s[i++];
            }
        }
        return ret + tmp;
    }

#ifdef DEBUG
    void Test()
    {
        Print(calculate(" 3+5 / 2 "));
    }
#endif /// DEBUG
};


}