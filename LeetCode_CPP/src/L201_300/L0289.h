
#pragma once

#include "../Head.h"

namespace L0289
{


/// https://leetcode.com/problems/game-of-life/
class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        const int M = board.size();
        if (0 == M)
        {
            return;
        }
        const int N = board[0].size();

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int count = 0;
                for (int I = (std::max)(i - 1, 0); I < (std::min)(i + 2, M); ++I)//本位也参与了计数
                {
                    for (int J = (std::max)(j - 1, 0); J < (std::min)(j + 2, N); ++J)//直接控制上限与下限，并变换方向；
                    {
                        count += board[I][J] & 1;//只有int中最后1bit参与运算，状态位被忽略
                    }
                }
                //包括两种情况：1.本位为1，周围有2个；2.本位为0，周围有三个；3.本位为1，周围有三个；
                if (3 == count || 3 == count - board[i][j])
                {
                    board[i][j] |= 2;//下一回合置为1
                }
            }
        }

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                board[i][j] >>= 1;
            }
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
        gameOfLife(test);
        Print(test);
    }
#endif /// DEBUG
};


}