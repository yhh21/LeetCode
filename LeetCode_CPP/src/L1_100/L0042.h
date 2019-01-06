#pragma once

#include "../Head.h"

namespace L0042
{
    // https://leetcode.com/problems/trapping-rain-water/description/
    class Solution
    {
    public:
        int trap(vector<int>& height)
        {
            int Length = height.size();
            if (Length < 2) return 0;

            int maxLeft = height[0];
            int maxRight = height[Length - 1];

            int res = 0;
            for (int i = 0, j = Length - 1; i <= j;)
            {
                if (height[i] <= height[j])
                {
                    if (height[i] > maxLeft)
                    {
                        maxLeft = height[i];
                    }
                    res += maxLeft - height[i];
                    ++i;
                }
                else
                {
                    if (height[j] > maxRight)
                    {
                        maxRight = height[j];
                    }
                    res += maxRight - height[j];
                    --j;
                }
            }

            return res;
        }
    };
}