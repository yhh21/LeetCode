#pragma once

#include "../Head.h"

namespace L0054
{
    /// https ://leetcode.com/problems/spiral-matrix/
    class Solution
    {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            vector<int> ret;
            const int M = matrix.size();
            if (0 == M) return ret;
            const int N = matrix[0].size();
            const int Min_Length = std::min(M, N);
            for (int i = 0; i * 2 < Min_Length; ++i)
            {
                int m = i, n = i;
                int flag = 0;
                while (flag < 4)
                {
                    switch (flag)
                    {
                    case 0:
                        if (n < N - i)
                        {
                            ret.push_back(matrix[m][n]);
                        }

                        if (n == N - i - 1)
                        {
                            ++flag;
                            ++m;

                            /// 处理只有一行的情况
                            if (m >= M - i) return ret;
                        }
                        else
                        {
                            ++n;
                        }
                        break;
                    case 1:
                        if (i < m && m < M - i)
                        {
                            ret.push_back(matrix[m][n]);
                        }

                        if (m >= M - i - 1)
                        {
                            ++flag;
                            --n;

                            /// 处理只有一行的情况
                            if (n < i) return ret;
                        }
                        else
                        {
                            ++m;
                        }
                        break;
                    case 2:
                        if (i <= n)
                        {
                            ret.push_back(matrix[m][n]);
                        }

                        n <= i ? (++flag, --m) : --n;
                        break;
                    case 3:
                        if (i < m)
                        {
                            ret.push_back(matrix[m][n]);
                        }

                        m <= i ? ++flag : --m;
                        break;
                    }
                }
            }

            return ret;
        }

    #ifdef DEBUG
        void Test()
        {
            vector<vector<int>> test;
            static const int M = 1,N = 3;
            for (int i = 0; i < M; ++i)
            {
                test.push_back(vector<int>(N, 0));
                for (int j = 0; j < N; ++j)
                {
                    test[i][j] = (i * N + j + 1);
                }
            }

            Print(spiralOrder(test));
        }
    #endif /// DEBUG
    };
}