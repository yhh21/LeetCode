
#pragma once

#include "../Head.h"

namespace L0322
{


/// https://leetcode.com/problems/coin-change/
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            for (int num : coins)
            {
                if (i - num >= 0)
                {
                    dp[i] = (std::min)(dp[i], dp[i - num] + 1);
                }
                else
                {
                    break;
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 5};
        Print(coinChange(test, 11));
    }
#endif /// DEBUG
};


}