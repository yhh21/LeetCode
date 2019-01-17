#pragma once

#include "../Head.h"

namespace L0078
{


/// https://leetcode.com/problems/combinations/
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        const int Length = nums.size();
        //std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        
        ret.push_back(tmp);
        Traverse(ret, nums, tmp, 0, Length);

        return ret;
    }

    void Traverse(vector<vector<int>> &ret, const vector<int> &nums
        , vector<int> &tmp, const int &start, const int &Length)
    {
        for (int i = start; i < Length; ++i)
        {
            //if (0 < i && nums[i] == nums[i - 1]) continue;
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            Traverse(ret, nums, tmp, i + 1, Length);
            tmp.pop_back();
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3};
        Print(subsets(test));
    }
#endif /// DEBUG
};


}