#pragma once

#include "../Head.h"

namespace L0075
{


/// https://leetcode.com/problems/sort-colors/
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        for (int i = 0, left = 0, right = nums.size() - 1; i <= right;)
        {
            if (0 == nums[i])
            {
                std::swap(nums[i], nums[left]);
                ++left;
                ++i;
            }
            else if (2 == nums[i])
            {
                std::swap(nums[i], nums[right]);
                --right;
            }
            else
            {
                ++i;
            }
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 0, 2, 1, 1, 0};
        sortColors(test);
        Print(test);
    }
#endif /// DEBUG
};


}