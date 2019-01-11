#pragma once

#include "../Head.h"

namespace L0060
{


/// https://leetcode.com/problems/permutation-sequence/
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<char> tmp;

        int weight = 1;
        for (int i = 1; ; ++i)
        {
            tmp.push_back(i + '0');
            if (i < n)
            {
                weight *= i;
            }
            else break;
        }

        string ret = "";
        --k;
        for (;;)
        {
            int index = k / weight;
            ret += tmp[index];
            tmp.erase(tmp.begin() + index);
            k = k % weight;
            if (tmp.size() > 0)
            {
                weight /= tmp.size();
            }
            else break;
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        Print(getPermutation(3, 3));
    }
#endif /// DEBUG
};


}