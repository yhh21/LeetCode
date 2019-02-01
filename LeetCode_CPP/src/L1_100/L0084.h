
#pragma once

#include "../Head.h"

namespace L0084
{


/// https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        const int Length = heights.size();

        int *low_from_left = new int[Length]();
        int *low_from_right = new int[Length]();

        low_from_left[0] = -1;
        low_from_right[Length - 1] = Length;
        
        for (int i = 1; i < Length; ++i)
        {
            int tmp = i - 1;
            for (; tmp >= 0 && heights[tmp] >= heights[i];)
            {
                tmp = low_from_left[tmp];
            }

            low_from_left[i] = tmp;
        }
        
        for (int i = Length - 2; i >= 0; --i)
        {
            int tmp = i + 1;
            for (; tmp < Length && heights[tmp] >= heights[i];)
            {
                tmp = low_from_right[tmp];
            }

            low_from_right[i] = tmp;
        }

        int ret = 0;
        for (int i = 0; i < Length; ++i)
        {
            ret = std::max(ret, heights[i] * (low_from_right[i] - low_from_left[i] - 1));
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {2, 1, 5, 6, 2, 3};

        Print(largestRectangleArea(test));
    }
#endif /// DEBUG
};


}