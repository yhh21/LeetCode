
#pragma once

#include "../Head.h"

namespace L0200
{


/// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        const int M = grid.size();
        if (0 == M)
        {
            return 0;
        }
        const int N = grid[0].size();

        int ret = 0;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if ('1' == grid[i][j])
                {
                    Recursive(grid, i, j, M, N);
                    ++ret;
                }
            }
        }

        return ret;
    }

    void Recursive(vector<vector<char>>& grid, int i, int j, const int &M, const int &N)
    {
        if ((i < 0 || j < 0 || i >= M || j >= N) || '1' != grid[i][j])
        {
            return;
        }

        grid[i][j] = '2';

        Recursive(grid, i, j - 1, M, N);
        Recursive(grid, i, j + 1, M, N);
        Recursive(grid, i - 1, j, M, N);
        Recursive(grid, i + 1, j, M, N);
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<char>> test = {
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '1'}
        };
        Print(numIslands(test));
    }
#endif /// DEBUG
};


}