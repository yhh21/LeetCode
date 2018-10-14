#pragma once

#include "../Head.h"

namespace L0042 {
    // https://leetcode.com/problems/trapping-rain-water/description/
    class Solution {
    public:
        int trap(vector<int>& height) {
            int Length = height.size();
            int *tmps = new int[Length]();

            int tmp = 0;
            for (int i = 0; i < Length; ++i) {
                tmps[i] = tmp;
                tmp = tmp > height[i] ? tmp : height[i];
            }

            int res = 0;
            tmp = 0;
            for (int i = Length - 1; i >= 0; --i) {
                tmps[i] = tmp < tmps[i] ? tmp : tmps[i];
                tmp = tmp > height[i] ? tmp : height[i];

                if (tmps[i] > height[i]) {
                    res += tmps[i] - height[i];
                }
            }

            return res;
        }
    };
}