#pragma once

#include "../Head.h"

namespace L0077
{


/// https://leetcode.com/problems/combinations/
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> tmp;
        Traverse(ret, tmp, 1,n, k);

        return ret;
    }

    void Traverse(vector<vector<int>> &ret, vector<int> &tmp, const int &start, const int &n, const int &k)
    {
        if (k == tmp.size())
        {
            ret.push_back(tmp);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            tmp.push_back(i);
            Traverse(ret, tmp, i + 1, n, k);
            tmp.pop_back();
        }
    }

#ifdef DEBUG
    void Test()
    {
        Print(combine(4, 2));
    }
#endif /// DEBUG
};


}