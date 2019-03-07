
#pragma once

#include "../Head.h"

namespace L0300
{


/// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        const int Length = nums.size();
        if (0 == Length)
        {
            return 0;
        }

        int ret = 1;
        vector<int> dp(Length, 1);
        for (int i = 1; i < Length; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = (std::max)(dp[i], dp[j] + 1);
                }
            }

            ret = (std::max)(ret, dp[i]);
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {10, 9, 2, 5, 3, 7, 101, 18};
        Print(lengthOfLIS(test));
    }
#endif /// DEBUG
};


}