
#pragma once

#include "../Head.h"

namespace L0287
{


/// https://leetcode.com/problems/find-the-duplicate-number/
class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[slow];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }

        return -1;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 3, 4, 2, 2};
        Print(findDuplicate(test));
    }
#endif /// DEBUG
};


}