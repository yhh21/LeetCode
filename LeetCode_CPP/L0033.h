#pragma once

#include "Head.h"

class Solution
{
public:
    int search(vector<int>& nums, int target) {
        int Length = nums.size();

        for (int start = 0, end = Length - 1; start <= end;) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;

            if (nums[start] <= nums[mid]) {
                nums[start] <= target && target < nums[mid] ? end = mid - 1 : start = mid + 1;
            }

            if (nums[mid] <= nums[end]) {
                nums[mid] < target && target <= nums[end] ? start = mid + 1: end = mid - 1;
            }
        }

        return -1;
    }
};