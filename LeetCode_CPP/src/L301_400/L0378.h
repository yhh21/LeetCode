
#pragma once

#include "../Head.h"

namespace L0378
{


/// https://leetcode.com/problems/top-k-frequent-elements/
class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        const int M = matrix.size();

        int left = matrix[0][0], right = matrix[M - 1][M - 1];
        while (left < right)
        {
            int mid = (right + left) / 2;
            int count = 0;
            for (int i = 0; i < M; ++i)
            {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                count += pos;
            }

            if (count < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{1, 1, 1}, {2, 2, 3}, {3, 3, 3}};
        Print(kthSmallest(test, 2));
    }
#endif /// DEBUG
};


}