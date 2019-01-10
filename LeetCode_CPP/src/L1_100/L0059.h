#pragma once

#include "../Head.h"

namespace L0059
{


/// https://leetcode.com/problems/spiral-matrix-ii/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int N)
    {
        vector<vector<int>> ret(N, vector<int>(N, 0));

        int num = 0;
        for (int i = 0; i * 2 < N; ++i)
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
                        ret[m][n] = ++num;
                    }

                    if (n == N - i - 1)
                    {
                        ++flag;
                        ++m;

                        /// 处理只有一行的情况
                        if (m >= N - i) return ret;
                    }
                    else
                    {
                        ++n;
                    }
                    break;
                case 1:
                    if (i < m && m < N - i)
                    {
                        ret[m][n] = ++num;
                    }

                    if (m >= N - i - 1)
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
                        ret[m][n] = ++num;
                    }

                    n <= i ? (++flag, --m) : --n;
                    break;
                case 3:
                    if (i < m)
                    {
                        ret[m][n] = ++num;
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
        Print(generateMatrix(2));
    }
#endif /// DEBUG
};


}