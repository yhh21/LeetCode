
#pragma once

#include "../Head.h"

namespace L0154
{


/// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
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
            if (nums[mid] > nums[j])
            {
                i = mid + 1;
            }
            else if (nums[mid] < nums[j])
            {
                j = mid;
            }
            else
            {
                --j;
            }
        }

        return nums[i];
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 1, 1, 1, 2, 1, 1};
        Print(findMin(test));
    }
#endif /// DEBUG
};


}