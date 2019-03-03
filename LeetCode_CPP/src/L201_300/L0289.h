
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
                for (int I = (std::max)(i - 1, 0); I < (std::min)(i + 2, M); ++I)//��λҲ�����˼���
                {
                    for (int J = (std::max)(j - 1, 0); J < (std::min)(j + 2, N); ++J)//ֱ�ӿ������������ޣ����任����
                    {
                        count += board[I][J] & 1;//ֻ��int�����1bit�������㣬״̬λ������
                    }
                }
                //�������������1.��λΪ1����Χ��2����2.��λΪ0����Χ��������3.��λΪ1����Χ��������
                if (3 == count || 3 == count - board[i][j])
                {
                    board[i][j] |= 2;//��һ�غ���Ϊ1
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