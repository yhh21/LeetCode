#pragma once

#include "../Head.h"

namespace L0051
{
    /// https://leetcode.com/problems/n-queens/
    class Solution
    {
    public:
        vector<vector<string>> solveNQueens(int n)
        {
            vector<vector<string>> ret;
            vector<string> queens(n, string(n, '.'));
            vector<bool> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);

            solveNQueens(ret, queens, flag_col, flag_45, flag_135, 0, n);

            return ret;
        }

        void solveNQueens(vector<vector<string>> &ret, vector<string> &queens, vector<bool> &flag_col
            , vector<bool> &flag_45, vector<bool> &flag_135, int row, const int &n)
        {
            if (n == row)
            {
                ret.push_back(queens);
                return;
            }

            for (int col = 0; col < n; ++col)
                if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row])
                {
                    flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                    queens[row][col] = 'Q';
                    solveNQueens(ret, queens, flag_col, flag_45, flag_135, row + 1, n);
                    queens[row][col] = '.';
                    flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
                }
        }

    #ifdef DEBUG
        void Test()
        {
            Print(solveNQueens(4));
        }
    #endif /// DEBUG
    };
}