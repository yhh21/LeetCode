
#pragma once

#include "../Head.h"

namespace L0240
{


/// https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const int M = matrix.size();
        if (0 == M)
        {
            return false;
        }
        const int N = matrix[0].size();

        for (int top = 0, right = N - 1; top < M && right >= 0;)
        {
            if (target == matrix[top][right])
            {
                return true;
            }
            else if (target > matrix[top][right])
            {
                ++top;
            }
            else
            {
                --right;
            }
        }

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{1, 2, 3}, {4, 5, 8}, {6, 7, 9}};
        Print(searchMatrix(test, 3));
    }
#endif /// DEBUG
};


}