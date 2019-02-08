
#pragma once

#include "../Head.h"

namespace L0120
{


/// https://leetcode.com/problems/triangle/
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = triangle.size() - 1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                triangle[i - 1][j] += (std::min)(triangle[i][j], triangle[i][j + 1]);
            }
        }

        return triangle[0][0];
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
        Print(minimumTotal(test));
    }
#endif /// DEBUG
};


}