#pragma once

#include "../Head.h"

namespace L0074
{


/// https://leetcode.com/problems/search-a-2d-matrix/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const int M = matrix.size();
        if (0 == M) return false;
        const int N = matrix[0].size();
        //if (0 == N) return false;

        for (int left = 0, right = M * N - 1; left <= right;)
        {
            int mid = (left + right) / 2;
            int m = mid / N, n = mid % N;

            if (target == matrix[m][n]) return true;
            else if (target > matrix[m][n])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

        Print(searchMatrix(test, 3));
    }
#endif /// DEBUG
};


}