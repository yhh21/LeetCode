
#pragma once

#include "../Head.h"

namespace L0162
{


/// https://leetcode.com/problems/find-peak-element/
class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int i = 0;
        for (int j = nums.size() - 1; i < j;)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }

        return i;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 0, 1};
        Print(findPeakElement(test));
    }
#endif /// DEBUG
};


}