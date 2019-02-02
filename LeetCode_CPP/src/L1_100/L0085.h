
#pragma once

#include "../Head.h"

namespace L0085
{


/// https://leetcode.com/problems/maximal-rectangle/
class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        const int M = matrix.size();
        if (0 == M) return 0;
        const int N = matrix[0].size();
        if (0 == N) return 0;

        int ret = 0;

        vector<int> left(N, 0);
        vector<int> right(N, N);
        vector<int> height(N, 0);

        for (int i = 0; i < M; ++i)
        {
            int cur_left = 0;
            int cur_right = N;

            for (int j = 0; j < N; ++j)
            {
                if ('1' == matrix[i][j])
                {
                    ++height[j];
                }
                else
                {
                    height[j] = 0;
                }
            }

            for (int j = 0; j < N; ++j)
            {
                if ('1' == matrix[i][j])
                {
                    left[j] = std::max(left[j], cur_left);
                }
                else
                {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = N - 1; j >= 0; --j)
            {
                if ('1' == matrix[i][j])
                {
                    right[j] = std::min(right[j], cur_right);
                }
                else
                {
                    right[j] = N;
                    cur_right = j;
                }
            }

            for (int j = 0; j < N; ++j)
            {
                ret = std::max(ret, (right[j] - left[j]) * height[j]);
            }
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<char>> test =
        {{'1' }};

        Print(maximalRectangle(test));
    }
#endif /// DEBUG
};


}