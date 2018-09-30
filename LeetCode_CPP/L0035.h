#pragma once

#include "Head.h"

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int Length = nums.size();
        int i = 0;
        for (; i < Length && nums[i] < target; ++i);

        return i;
    }
};
