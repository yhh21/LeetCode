#pragma once

#include "../Head.h"

namespace L0014
{
    class Solution
    {
    public:
        static string longestCommonPrefix(vector<string>& strs)
        {
            if (strs.size() == 0) return "";

            int minLength = INT32_MAX;
            for (auto _iterator = strs.begin(); _iterator != strs.end(); ++_iterator)
            {
                int tmpLength = _iterator->length();
                minLength = minLength <= tmpLength ? minLength : tmpLength;
            }

            int prefixIndex = 0;
            for (prefixIndex = 0; prefixIndex < minLength; ++prefixIndex)
            {
                auto _iterator = strs.begin();
                char tmpChar = _iterator->at(prefixIndex);
                for (++_iterator; _iterator != strs.end(); ++_iterator)
                {
                    if (tmpChar != _iterator->at(prefixIndex)) goto BREAK_MULTIPLE_LOOP;
                }
            }

        BREAK_MULTIPLE_LOOP:
            return strs.begin()->substr(0, prefixIndex);
        }
    };
}