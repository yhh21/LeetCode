#pragma once

#include "../Head.h"

namespace L0064
{


/// https://leetcode.com/problems/minimum-path-sum/
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int M = grid.size();
        if (0 == M) return 0;
        int N = grid[0].size();
        if (0 == N) return 0;

        for (int i = 1; i < M; ++i)
        {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < N; ++j)
        {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < M; ++i)
        {
            for (int j = 1; j < N; ++j)
            {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[M - 1][N - 1];
    }
};


}