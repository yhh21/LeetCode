
#pragma once

#include "../Head.h"

namespace L0131
{


/// https://leetcode.com/problems/palindrome-partitioning/
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        if (s.empty())
        {
            return ret;
        }

        vector<string> path;
        DFS(0, s, path, ret);

        return ret;
    }

    void DFS(int index, const string &s, vector<string> &path, vector<vector<string>> &ret)
    {
        const int Length = s.size();
        if (Length == index)
        {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < Length; ++i)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                DFS(i + 1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

#ifdef DEBUG
    void Test()
    {
        Print(partition("aab"));
    }
#endif /// DEBUG
};


}