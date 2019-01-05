#pragma once

#include "../Head.h"

namespace L0047
{
    /// https://leetcode.com/problems/permutations-ii/
    class Solution
    {
    public:
        vector<vector<int>> permuteUnique(vector<int> &num)
        {
            vector<vector<int>> ret;
            const int Length = num.size();

            if (Length > 0)
            {
                sort(num.begin(), num.end());

                Recursive(ret, num, 0, Length);
            }

            return ret;
        }

        void Recursive(vector<vector<int>> &ret, vector<int> nums, const int &index, const int &Length)
        {
            if (Length - 1 == index)
            {
                ret.push_back(nums);
                return;
            }

            Recursive(ret, index + 1, nums, Length);
            for (int i = index + 1; i < Length; ++i)
            {
                if (nums[index] == nums[i]) continue;

                swap(nums[index], nums[i]);
                Recursive(ret, index + 1, nums, Length);
            }
        }

        void Test()
        {
            vector<int> test;
            test.push_back(1);
            test.push_back(1);
            test.push_back(2);

            auto t = permuteUnique(test);
        }
    };
}