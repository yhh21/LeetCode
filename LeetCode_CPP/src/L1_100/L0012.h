#pragma once

#include "../Head.h"

namespace L0012
{
    class Solution
    {
    public:
        // better solution
        map<int, string> mapRoman = {{1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"}, {1, "I"}};

        string intToRoman(int num)
        {
            string res;

            for (auto it = mapRoman.rbegin(), end = mapRoman.rend(); it != end; ++it)
            {
                for (; num >= it->first; num -= it->first)
                {
                    res += it->second;
                }
            }

            return res;
        }
    };
}