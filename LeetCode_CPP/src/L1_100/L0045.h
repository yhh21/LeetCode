#pragma once

#include "../Head.h"

namespace L0045
{
    /// https://leetcode.com/problems/jump-game-ii/
    class Solution
    {
    public:
        int jump(vector<int>& nums)
        {
            int Length = nums.size();
            int jumps = 0, curEnd = 0, curFarthest = 0;

            for (int i = 0; i < Length - 1; ++i)
            {
                curFarthest = max(curFarthest, i + nums[i]);
                if (i == curEnd)
                {
                    ++jumps;
                    curEnd = curFarthest;

                    if (curEnd >= Length - 1) break;
                }
            }

            return jumps;
        }

    #ifdef DEBUG
        void Test()
        {
            vector<int> test;
            test.push_back(1);
            test.push_back(1);
            test.push_back(2);
            test.push_back(1);
            test.push_back(4);

            jump(test);
        }
    #endif /// DEBUG
    };
}