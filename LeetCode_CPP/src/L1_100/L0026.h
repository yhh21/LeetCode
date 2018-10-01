#pragma once

#include "../Head.h"

namespace L0026 {
    class Solution {
    public:
        static int removeDuplicates(vector<int>& nums) {
            int Lenght = nums.size();
            if (Lenght == 0) return 0;

            int res = 1;
            for (int i = 1, tmp = nums[0]; i < Lenght; ++i) {
                if (nums[i] != tmp) {
                    nums[res++] = nums[i];
                    tmp = nums[i];
                }
            }

            return res;
        }
    };
}