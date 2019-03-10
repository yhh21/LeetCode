
#pragma once

#include "../Head.h"

namespace L0347
{


/// https://leetcode.com/problems/top-k-frequent-elements/
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> uo_map;
        for (int num : nums)
        {
            ++uo_map[num];
        }

        vector<pair<int, int>> sort_vec;
        for (auto p : uo_map)
        {
            sort_vec.push_back(p);
        }
        sort(sort_vec.begin(), sort_vec.end(), [](pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        });

        vector<int> ret;
        //const int Length = sort_vec.size();
        for (int i = 0; i < k /*&& i < Length*/; ++i)
        {
            ret.push_back(sort_vec[i].first);
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 1, 1, 2, 2, 3,3,3,3};
        Print(topKFrequent(test, 2));
    }
#endif /// DEBUG
};


}