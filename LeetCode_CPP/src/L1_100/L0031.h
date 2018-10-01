#pragma once

#include "../Head.h"

namespace L0031 {
    class Solution
    {
    public:
        void nextPermutation(vector<int>& nums) {
            int Length = nums.size();

            int i = Length - 2;
            for (; i >= 0 && nums[i] >= nums[i + 1]; --i);

            if (i >= 0) {
                int j = i + 1;
                for (; j < Length && nums[i] < nums[j]; ++j);

                Swap(nums, i, j - 1);
            }

            ++i;
            for (int j = Length - 1; i < j; ++i, --j) {
                Swap(nums, i, j);
            }
        }

        void Swap(vector<int>& nums, int i, int j) {
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }
    };
}