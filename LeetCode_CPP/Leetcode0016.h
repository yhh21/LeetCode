#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Leetcode0016
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int diff = INT_MAX;
        const int Length = nums.size();

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

                if (sum < target) {
                    ++j;
                }
                else if (sum > target) {
                    --k;
                }
                else {
                    break;
                }
            }
        }

        return res;
    }
};