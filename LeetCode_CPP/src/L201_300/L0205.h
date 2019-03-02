
#pragma once

#include "../Head.h"

namespace L0205
{


/// https://leetcode.com/problems/isomorphic-strings/
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        const int Length = s.size();

        unordered_map<char, char> _map;
        unordered_set<char> _set;

        for (int i = 0; i < Length; ++i)
        {
            if (_map.count(s[i]))
            {
                if (_map[s[i]] != t[i])
                {
                    return false;
                }
            }
            else if (_set.count(t[i]))
            {
                return false;
            }
            else
            {
                _map.insert(pair<char, char>(s[i], t[i]));
                _set.insert(t[i]);
            }
        }

        return true;
    }

#ifdef DEBUG
    void Test()
    {
        Print(isIsomorphic("ad", "aa"));
    }
#endif /// DEBUG
};


}