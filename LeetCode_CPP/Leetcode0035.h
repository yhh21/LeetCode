#pragma once

#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Leetcode0035 {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int Length = nums.size();
        int i = 0;
        for (; i < Length; ++i) {
            if (nums[i] >= target) {
                break;
            }
        }

        //nums.insert(nums.begin() + i, target);
        return i;
    }
};
