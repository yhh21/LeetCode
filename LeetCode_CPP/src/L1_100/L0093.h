
#pragma once

#include "../Head.h"

namespace L0093
{


/// https://leetcode.com/problems/restore-ip-addresses/
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        const int Length = s.size();
        vector<string> ret;

        for (int i1 = 1; i1 <= 3; ++i1)
        {
            if (!IsValidIpNum(s, 0, i1))
            {
                continue;
            }

            for (int i2 = i1; i2 <= i1 + 3; ++i2)
            {
                if (!IsValidIpNum(s, i1, i2))
                {
                    continue;
                }

                for (int i3 = i2; i3 <= i2 + 3; ++i3)
                {
                    if (!IsValidIpNum(s, i2, i3))
                    {
                        continue;
                    }

                    if (!IsValidIpNum(s, i3, Length))
                    {
                        continue;
                    }

                    ret.push_back(s.substr(0, i1) + "." + s.substr(i1, i2 - i1)
                        + "." + s.substr(i2, i3 - i2) + "." + s.substr(i3, Length - i3));
                }
            }
        }

        return ret;
    }

    bool IsValidIpNum(const string &s, const int &start, const int &end)
    {
        const int Length = end - start;
        if (Length > 3 || Length <= 0)
        {
            return false;
        }

        if (1 != Length && '0' == s[start])
        {
            return false;
        }

        if (3 == Length && (s[start] > '2'
            || ('2' == s[start] && ('5' < s[start + 1]
                ||('5' == s[start + 1] && '5' < s[start + 2])))))
        {
            return false;
        }

        return true;
    }

#ifdef DEBUG
    void Test()
    {
        Print(restoreIpAddresses("000256"));
    }
#endif /// DEBUG
};


}