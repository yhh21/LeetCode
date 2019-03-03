
#pragma once

#include "../Head.h"

namespace L0239
{


/// https://leetcode.com/problems/sliding-window-maximum/
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        const int Length = nums.size();
        if (Length < 1)
        {
            return nums;
        }
        vector<int> max_left(Length);
        vector<int> max_right(Length);

        max_left[0] = nums[0];
        for (int i = 1; i < Length; ++i)
        {
            max_left[i] = 0 == (i % k) ? nums[i] : (std::max)(max_left[i - 1], nums[i]);
        }
        max_right[Length - 1] = nums[Length - 1];
        for (int j = Length - 2; j >= 0 ; --j)
        {
            max_right[j] = 0 == (j % k) ? nums[j] : (std::max)(max_right[j + 1], nums[j]);
        }

        vector<int> sliding_max(Length - k + 1);
        for (int i = 0; i + k - 1 < Length; ++i)
        {
            sliding_max[i] = (std::max)(max_right[i], max_left[i + k - 1]);
        }

        return sliding_max;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 3, -1, -3, 5, 3, 6, 7};
        Print(maxSlidingWindow(test, 3));
    }
#endif /// DEBUG
};


}