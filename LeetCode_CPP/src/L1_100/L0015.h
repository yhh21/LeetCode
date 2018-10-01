#pragma once

#include "../Head.h"

namespace L0015 {
    class Solution
    {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            vector<vector<int>> res;
            vector<int> *tmp;
            const int Length = nums.size();

            for (int i = 0; i < Length - 2 && nums[i] <= 0;) {
                for (int j = i + 1, k = Length - 1; j < k;) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        tmp = new vector<int>();
                        tmp->push_back(nums[i]);
                        tmp->push_back(nums[j]);
                        tmp->push_back(nums[k]);
                        res.push_back(*tmp);
                    }

                    if (sum <= 0) {
                        for (++j; j < k && nums[j - 1] == nums[j]; ++j);
                    }

                    if (sum >= 0) {
                        for (--k; j < k && nums[k] == nums[k + 1]; --k);
                    }
                }

                for (++i; i < Length - 2 && nums[i - 1] == nums[i]; ++i);
            }

            return res;
        }
    };
}