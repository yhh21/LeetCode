
#pragma once

#include "../Head.h"

namespace L0329
{


/// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        const int M = matrix.size();
        if (0 == M)
        {
            return 0;
        }
        const int N = matrix[0].size();

        int ret = 1;
        vector<vector<int>> cache(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                ret = (std::max)(ret, DFS(matrix, i, j, M, N, cache));
            }
        }

        return ret;
    }

    int DFS(vector<vector<int>> &matrix, int i, int j, const int &M, const int &N, vector<vector<int>> &cache)
    {
        if (0 != cache[i][j])
        {
            return cache[i][j];
        }

        static vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int ret = 1;
        for (auto dir : dirs)
        {
            int x = i + dir[0];
            int y = j + dir[1];
            if ((x < 0 || x >= M || y < 0 || y >= N) || matrix[x][y] <= matrix[i][j])
            {
                continue;
            }

            ret = (std::max)(ret, DFS(matrix, x, y, M, N, cache) + 1);
        }

        return cache[i][j] = ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
        Print(longestIncreasingPath(test));
    }
#endif /// DEBUG
};


}