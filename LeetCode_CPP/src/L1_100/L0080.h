
#pragma once

#include "../Head.h"

namespace L0080
{


/// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        const int Length = nums.size();
        int ret = 0;
        for (int i = 0; i < Length; ++i)
        {
            int tmp = nums[i];
            if (ret < 2 || tmp > nums[ret - 2])
            {
                nums[ret++] = tmp;
            }
        }
        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        Print(removeDuplicates(test));
    }
#endif /// DEBUG
};


}