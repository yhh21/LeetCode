
#pragma once

#include "../Head.h"

namespace L0215
{


/// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        const int Length = nums.size();

        for (int i = 0; i < k; ++i)
        {
            for (int j = i + 1; j < Length; ++j)
            {
                if (nums[j] > nums[i])
                {
                    std::swap(nums[i], nums[j]);
                }
            }
        }

        return nums[k - 1];
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 2, 1, 5, 6, 4};
        Print(findKthLargest(test, 2));
    }
#endif /// DEBUG
};


}