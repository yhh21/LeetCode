#pragma once

#include "../Head.h"

namespace L0079
{


/// https://leetcode.com/problems/word-search/
class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        const int M = board.size();
        if (0 == M) return false;
        const int N = board[0].size();
        const int Length = word.size();
        vector<vector<int>> visit(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (HasWord(board, visit, word, i, j, 0, M, N, Length)) return true;
            }
        }

        return false;
    }

    bool HasWord(vector<vector<char>>& board, vector<vector<int>> &visit, const string &word
        , const int &i, const int &j
        , const int &start, const int &M, const int &N, const int &Length)
    {
        if (start >= Length) return true;
        if (i < 0 || i >= M || j < 0 || j >= N || 1 == visit[i][j] || board[i][j] != word[start]) return false;

        visit[i][j] = 1;

        if (   HasWord(board, visit, word, i - 1, j, start + 1, M, N, Length)
            || HasWord(board, visit, word, i + 1, j, start + 1, M, N, Length)
            || HasWord(board, visit, word, i, j - 1, start + 1, M, N, Length)
            || HasWord(board, visit, word, i, j + 1, start + 1, M, N, Length)) return true;

        visit[i][j] = 0;

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        //vector<vector<char>> test = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        vector<vector<char>> test = {{'A', 'B'}, {'C', 'D'}};
        string testStr = "ACDB";
        Print(exist(test, testStr));
    }
#endif /// DEBUG
};


}