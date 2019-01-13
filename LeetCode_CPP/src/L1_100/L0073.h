#pragma once

#include "../Head.h"

namespace L0073
{


/// https://leetcode.com/problems/set-matrix-zeroes/
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        const int M = matrix.size();
        if (0 == M) return;
        const int N = matrix[0].size();
        if (0 == N) return;

        bool is_zero_first_row = false;
        for (int i = 0; i < M; ++i)
        {
            if (0 == matrix[i][0])
            {
                is_zero_first_row = true;
            }
            for (int j = 1; j < N; ++j)
            {
                if (0 == matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = M - 1; i >= 0; --i)
        {
            for (int j = N - 1; j > 0; --j)
            {
                if (0 == matrix[i][0] || 0 == matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
            if (is_zero_first_row)
            {
                matrix[i][0] = 0;
            }
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test(3, vector<int>(3, 1));
        test[1][1] = 0;

        setZeroes(test);

        Print(test);
    }
#endif /// DEBUG
};


}