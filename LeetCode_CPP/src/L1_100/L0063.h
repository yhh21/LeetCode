#pragma once

#include "../Head.h"

namespace L0063
{


/// https://leetcode.com/problems/unique-paths-ii/
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int M = obstacleGrid.size();
        if (0 == M) return 0;
        int N = obstacleGrid[0].size();
        if (0 == N) return 0;

        if (1 == obstacleGrid[0][0]) return 0;

        obstacleGrid[0][0] = 1;
        for (int i = 1; i < M; ++i)
        {
            obstacleGrid[i][0] = (1 == obstacleGrid[i][0]) ? 0 : obstacleGrid[i - 1][0];
        }
        for (int j = 1; j < N; ++j)
        {
            obstacleGrid[0][j] = (1 == obstacleGrid[0][j]) ? 0 : obstacleGrid[0][j - 1];
        }

        for (int i = 1; i < M; ++i)
        {
            for (int j = 1; j < N; ++j)
            {
                obstacleGrid[i][j] = (1 == obstacleGrid[i][j]) ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        return obstacleGrid[M - 1][N - 1];
    }
};


}