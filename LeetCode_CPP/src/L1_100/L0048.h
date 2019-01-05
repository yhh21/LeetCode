#pragma once

#include "../Head.h"

namespace L0048
{
    /// https://leetcode.com/problems/rotate-image/
    class Solution
    {
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            const int Length = matrix.size();

            /// x' = y, y' = L - 1 - x

            for (int i = 0; i * 2 < Length; ++i)
            {
                for (int j = i; j < Length - i - 1; ++j)
                {
                    int x = i, y = j;
                    int tmp = matrix[x][y];

                    for (int k = 0; k < 4; ++k)
                    {
                        int x1 = y;
                        int y1 = Length - 1 - x;

                        swap(tmp, matrix[x1][y1]);

                        x = x1;
                        y = y1;
                    }
                }
            }
        }

        void Test()
        {
            vector<vector<int>> test;
            static const int N = 4;
            test.resize(N);
            for (int i = 0; i < N; ++i)
            {
                test[i].resize(N);
                for (int j = 0; j < N; ++j)
                {
                    test[i][j] = (i * N + j + 1);
                }
            }

            Print(test);

            rotate(test);

            Print(test);
        }
    };
}