#pragma once

#include "../Head.h"

namespace L0055
{
    /// https://leetcode.com/problems/jump-game/
    class Solution
    {
    public:
        bool canJump(vector<int>& nums)
        {
            const int Length = nums.size();
            if (1 >= Length) return true;

            int max_dis = nums[0];
            for (int i = 1; i <= max_dis; ++i)
            {
                max_dis = std::max(max_dis, i + nums[i]);
                if (max_dis >= Length - 1) return true;
            }

            return false;
        }

    #ifdef DEBUG
        void Test()
        {
            vector<int> test = {1, 2, 3};

            Print(canJump(test));
        }
    #endif /// DEBUG
    };
}