
#pragma once

#include "../Head.h"

namespace L0188
{


/// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        const int Length = prices.size();
        if (k >= Length / 2)
        {
            return QuickSolve(prices);
        }

        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 1; i < Length; ++i)
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; --j)
            {
                l[j] = (std::max)(g[j - 1] + (std::max)(diff, 0), l[j] + diff);
                g[j] = (std::max)(g[j], l[j]);
            }
        }

        return g[k];
    }

    int QuickSolve(vector<int>& prices)
    {
        const int Length = prices.size();
        int profit = 0;
        for (int i = 1; i < Length; ++i)
        {
            // as long as there is a price gap, we gain a profit.
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 2, 6, 5, 0, 3};
        Print(maxProfit(2, test));
    }
#endif /// DEBUG
};


}