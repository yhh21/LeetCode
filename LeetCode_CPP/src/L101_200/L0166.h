
#pragma once

#include "../Head.h"

namespace L0166
{


/// https://leetcode.com/problems/fraction-to-recurring-decimal/
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (0 == numerator)
        {
            return "0";
        }

        string ret;
        if (numerator < 0 ^ denominator < 0)
        {
            ret += '-';
        }
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        ret += to_string(integral);
        long rmd = numer % denom;
        if (0 == rmd)
        {
            return ret;
        }
        ret += '.';
        rmd *= 10;
        unordered_map<long, long> uo_map;
        for (; 0 != rmd;)
        {
            long quotient = rmd / denom;
            if (uo_map.find(rmd) != uo_map.end())
            {
                ret.insert(uo_map[rmd], 1, '(');
                ret += ')';
                break;
            }
            uo_map[rmd] = ret.size();
            ret += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        Print(fractionToDecimal(2, 3));
    }
#endif /// DEBUG
};


}