
#pragma once

#include "../Head.h"

namespace L0324
{


/// https://leetcode.com/problems/wiggle-sort-ii/
class Solution
{
public:
    void wiggleSort(vector<int>& nums)
    {
        const int Length = nums.size();

        // Find a median.
        auto midptr = nums.begin() + Length / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (Length|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = Length - 1;
        while (j <= k)
        {
            if (A(j) > mid)
            {
                swap(A(i++), A(j++));
            }
            else if (A(j) < mid)
            {
                swap(A(j), A(k--));
            }
            else
            {
                ++j;
            }
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 5, 1, 1, 6, 4};
        wiggleSort(test);
        Print(test);
    }
#endif /// DEBUG
};


}