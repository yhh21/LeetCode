#pragma once

#include "../Head.h"

namespace L0053
{
    class Solution
    {
    public:
        static int maxSubArray(vector<int>& nums)
        {
            int Length = nums.size();

            int res = nums[0];
            int tmp = nums[0];

            for (int i = 1; i < Length; ++i)
            {
                tmp = tmp > 0 ? tmp : 0;
                tmp + nums[i] > 0 ? (tmp += nums[i], res = (res > tmp ? res : tmp)) :
                    (tmp = nums[i], res = (res > nums[i] ? res : nums[i]));
            }

            return res;
        }
    };
}