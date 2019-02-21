
#pragma once

#include "../Head.h"

namespace L0174
{


/// https://leetcode.com/problems/dungeon-game/
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        const int M = dungeon.size();
        const int N = dungeon[0].size();

        vector<int> dp(N + 1, INT_MAX);

        for (int i = M - 1; i >= 0; --i)
        {
            for (int j = N - 1; j >= 0; --j)
            {
                if (M - 1 == i && N - 1 == j)
                {
                    dp[j] = 1 - dungeon[i][j];
                }
                else if (N - 1 == j)
                {
                    dp[j] -= dungeon[i][j];
                }
                else
                {
                    dp[j] = (std::min)(dp[j], dp[j + 1]) - dungeon[i][j];
                }

                dp[j] = (std::max)(1, dp[j]);
            }
        }

        return dp[0];
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
        Print(calculateMinimumHP(test));
    }
#endif /// DEBUG
};


}