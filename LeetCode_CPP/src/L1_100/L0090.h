
#pragma once

#include "../Head.h"

namespace L0090
{


/// https://leetcode.com/problems/subsets-ii/
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ret;
        vector<int> tmp;

        sort(nums.begin(), nums.end());
        SubsetsWithDup(ret, tmp, nums, 0, nums.size());

        return ret;
    }

    void SubsetsWithDup(vector<vector<int>> &ret, vector<int>& tmp, const vector<int>& nums
        , int start, const int &end)
    {
        ret.push_back(tmp);

        for (int i = start; i < end; ++i)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            tmp.push_back(nums[i]);
            SubsetsWithDup(ret, tmp, nums, i + 1, end);
            tmp.pop_back();
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 2};

        Print(subsetsWithDup(test));
    }
#endif /// DEBUG
};


}