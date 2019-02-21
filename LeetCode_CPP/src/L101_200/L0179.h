
#pragma once

#include "../Head.h"

namespace L0179
{


/// https://leetcode.com/problems/largest-number/
class Solution
{
public:
    string largestNumber(vector<int> &num)
    {
        vector<string> vec;
        for (auto i : num)
        {
            vec.push_back(to_string(i));
        }
        sort(begin(vec), end(vec), [](string &s1, string &s2)
        {
            return s1 + s2 > s2 + s1;
        });

        string ret;
        for (auto s : vec)
        {
            ret += s;
        }
        for (; ret[0] == '0' && ret.length() > 1;)
        {
            ret.erase(0, 1);
        }

        return  ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 1, 10, 30};
        Print(largestNumber(test));
    }
#endif /// DEBUG
};


}