#pragma once

#include "../Head.h"

namespace L0018 {
    class Solution
    {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

            vector<vector<int>> res;
            vector<int> *tmp;
            const int Length = nums.size();

            for (int i = 0; i < Length - 3;) {
                for (int j = i + 1; j < Length - 2;) {
                    int headSum = nums[i] + nums[j];
                    if (nums[j] >= 0 && headSum > target) break;

                    for (int k = j + 1, l = Length - 1; k < l;) {
                        int sum = headSum + nums[k] + nums[l];
                        if (sum == target) {
                            tmp = new vector<int>();
                            tmp->push_back(nums[i]);
                            tmp->push_back(nums[j]);
                            tmp->push_back(nums[k]);
                            tmp->push_back(nums[l]);
                            res.push_back(*tmp);
                        }

                        if (sum <= target) {
                            for (++k; k < l && nums[k - 1] == nums[k]; ++k);
                        }

                        if (sum >= target) {
                            for (--l; k < l && nums[l] == nums[l + 1]; --l);
                        }
                    }

                    for (++j; j < Length - 2 && nums[j - 1] == nums[j]; ++j);
                }

                for (++i; i < Length - 3 && nums[i - 1] == nums[i]; ++i);
            }

            return res;
        }
    };
}