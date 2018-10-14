#pragma once

#include "../Head.h"

namespace L0041 {
    // https://leetcode.com/problems/first-missing-positive/description/
    class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int Length = nums.size();

            for (int i = 0; i < Length;) {
                int tmp = nums[i];
                if (tmp != i + 1 && (tmp >= 1 && tmp <= Length) && nums[tmp - 1] != tmp) {
                    int t = nums[tmp - 1];
                    nums[tmp - 1] = tmp;
                    nums[i] = t;
                }
                else {
                    ++i;
                }
            }

            for (int i = 0; i < Length; ++i) {
                if (nums[i] != i + 1) return i + 1;
            }

            return Length + 1;
        }
    };
}