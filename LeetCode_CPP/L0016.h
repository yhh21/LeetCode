#pragma once

#include "Head.h"

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int Length = nums.size();

        int res = 0;
        int diff = INT_MAX;

        for (int i = 0; i < Length - 2; ++i) {
            for (int j = i + 1, k = Length - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                int tmp_diff = target - sum;
                if (tmp_diff < 0) {
                    tmp_diff *= -1;
                }

                if (tmp_diff < diff) {
                    res = sum;
                    diff = tmp_diff;
                }

                if (sum == target) break;
                sum < target ? ++j : --k;
            }
        }

        return res;
    }
};