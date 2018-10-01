#pragma once

#include "../Head.h"

namespace L0040 {
    class Solution {
    public:
        vector<vector<int>> res;
        vector<int> comb;
        int Length;

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            Length = candidates.size();
            BackTracking(candidates, target, 0);

            return res;
        }

        void BackTracking(vector<int>& candidates, int sum, int index) {
            if (sum == 0) {
                res.push_back(comb);
                return;
            }
            else if (sum < 0) return;

            for (int i = index; i < Length; ++i) {
                int tmp = candidates[i];
                if (tmp > sum) break;

                comb.push_back(tmp);
                BackTracking(candidates, sum - tmp, i + 1);
                comb.pop_back();

                for (; tmp == candidates[i + 1]; ++i);
            }
        }
    };
}