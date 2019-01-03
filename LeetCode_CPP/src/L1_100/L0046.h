#pragma once

#include "../Head.h"

namespace L0046
{
    /// https://leetcode.com/problems/permutations/
    class Solution
    {
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            const int Length = nums.size();
            int ret_Length = Length;
            for (int i = Length - 1; i > 0; --i)
            {
                ret_Length *= i;
            }

            vector<vector<int>> ret;
            ret.reserve(ret_Length);
            vector<int> tmp;
            tmp.reserve(Length);

            Recursive(ret, tmp, nums, Length);

            return ret;
        }

        void Recursive(vector<vector<int>> &ret, vector<int> &tmp, const vector<int> &nums, const int &Length)
        {
            const int tmp_Length = tmp.size();
            if (Length == tmp_Length)
            {
                ret.push_back(tmp);
                return;
            }

            for (int i = 0; i < Length; ++i)
            {
                bool is_find = false;
                for (int j = 0; j < tmp_Length; ++j)
                {
                    if (tmp[j] == nums[i])
                    {
                        is_find = true;
                        break;
                    }
                }
                if (is_find) continue;

                tmp.push_back(nums[i]);
                Recursive(ret, tmp, nums, Length);
                tmp.pop_back();
            }
        }

        void Test()
        {
            vector<int> test;
            test.push_back(1);
            test.push_back(2);
            test.push_back(3);

            auto t = permute(test);
        }
    };
}