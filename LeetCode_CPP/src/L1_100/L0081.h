
#pragma once

#include "../Head.h"

namespace L0081
{


/// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/
class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        for (int left = 0, right = nums.size() - 1; left <= right;)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return true;
            }

            // the only difference from the first one, trickly case, just updat left and right
            if ((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
            {
                ++left;
                --right;
            }
            else if (nums[left] <= nums[mid])
            {
                if ((nums[left] <= target) && (nums[mid] > target))
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if ((nums[mid] < target) && (nums[right] >= target))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 5, 6, 0, 0, 1, 2};
        Print(search(test, 0));
    }
#endif /// DEBUG
};


}