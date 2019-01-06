#pragma once

#include "../Head.h"

namespace L0066
{
    class Solution
    {
    public:
        static vector<int> plusOne(vector<int>& digits)
        {
            int Length = digits.size();
            int tag = 0;

            ++digits[Length - 1];

            for (int i = Length - 1; i >= 0; --i)
            {
                int tmp = tag + digits[i];
                digits[i] = (tmp) % 10;
                tag = (tmp) / 10;

                if (tag == 0) break;
            }

            if (tag != 0)
            {
                digits.insert(digits.begin(), tag);
            }

            return digits;
        }
    };
}