#pragma once

#include "../Head.h"

namespace L0037 {
    constexpr int N = 9;

    class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            IsSolveSudoku(board);
        }

        bool IsSolveSudoku(vector<vector<char>>& board) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    auto p = &board[i][j];
                    if ((*p) == '.') {
                        for (int k = 1; k <= 9; ++k) {
                            (*p) = (char)('0' + k);
                            if (IsValid(board, i, j) && IsSolveSudoku(board)) return true;
                            (*p) = '.';
                        }
                        return false;
                    }
                }
            }

            return true;
        }

        bool IsValid(vector<vector<char>>& board, int col, int row) {
            for (int i = 0; i < N; ++i) {
                if (i != col && board[i][row] == board[col][row]) return false;
            }

            for (int i = 0; i < N; ++i) {
                if (i != row && board[col][i] == board[col][row]) return false;
            }

            int colStart = col / 3 * 3;
            int colEnd = colStart + 3;
            int rowStart = row / 3 * 3;
            int rowEnd = rowStart + 3;
            for (int i = colStart; i < colEnd; ++i) {
                for (int j = rowStart; j < rowEnd; ++j) {
                    if (i != col && j != row && board[i][j] == board[col][row]) return false;
                }
            }

            return true;
        }
    };
}