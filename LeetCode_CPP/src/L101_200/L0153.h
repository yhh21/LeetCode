
#pragma once

#include "../Head.h"

namespace L0153
{


/// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int i = 0;
        for (int j = nums.size() - 1; i < j;)
        {
            if (nums[i] < nums[j])
            {
                return nums[i];
            }

            int mid = (i + j) / 2;
            if (nums[i] <= nums[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }

        return nums[i];
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 3, 0, 1};
        Print(findMin(test));
    }
#endif /// DEBUG
};


}