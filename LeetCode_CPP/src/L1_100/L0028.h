#pragma once

#include "../Head.h"

namespace L0028
{
    class Solution
    {
    public:
        static int strStr(string haystack, string needle)
        {
            int Length2 = needle.length();
            if (Length2 == 0) return 0;

            int Length1 = haystack.length() - Length2;

            for (int i = 0; i <= Length1; ++i)
            {
                bool isFind = true;
                for (int j = 0; j < Length2; ++j)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        isFind = false;
                        break;
                    }
                }

                if (isFind) return i;
            }

            return -1;
        }
    };
}