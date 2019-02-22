
#pragma once

#include "../Head.h"

namespace L0198
{


/// https://leetcode.com/problems/house-robber/
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        const int Length = nums.size();
        if (Length < 1)
        {
            return 0;
        }
        else if (Length < 2)
        {
            return nums[0];
        }

        vector<int> dp(Length, 0);
        dp[0] = nums[0];
        dp[1] = (std::max)(nums[0], nums[1]);
        for (int i = 2; i < Length; ++i)
        {
            dp[i] = (std::max)(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[Length - 1];
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3, 1};
        Print(rob(test));
    }
#endif /// DEBUG
};


}