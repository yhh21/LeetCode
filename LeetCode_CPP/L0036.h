#pragma once

#include "Head.h"

#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>

constexpr int N = 9;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vvb col = vvb(N, vb(10, false));
        vvb row = vvb(N, vb(10, false));
        vvvb rec = vvvb(N / 3, vvb(N / 3, vb(10, false)));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int tmp = (int)(c - '0');
                    if (!col[i][tmp] && !row[j][tmp] && !rec[i / 3][j / 3][tmp]) {
                        col[i][tmp] = row[j][tmp] = rec[i / 3][j / 3][tmp] = true;
                    }
                    else return false;
                }
            }
        }

        return true;
    }
};