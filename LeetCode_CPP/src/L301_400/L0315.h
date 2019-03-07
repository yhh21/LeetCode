
#pragma once

#include "../Head.h"

namespace L0315
{


/// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        const int Length = nums.size();

        vector<int> ret(Length, 0);
        vector<int> indices(Length, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, Length, ret, nums);

        return ret;
    }

    void merge_countSmaller(vector<int>& indices, int first, int last,
        vector<int>& ret, vector<int>& nums)
    {
        int count = last - first;
        if (count > 1)
        {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, ret, nums);
            merge_countSmaller(indices, mid, last, ret, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last))
            {
                if ((idx2 == last) || ((idx1 < mid) &&
                    (nums[indices[idx1]] <= nums[indices[idx2]])))
                {
                    tmp.push_back(indices[idx1]);
                    ret[indices[idx1]] += semicount;
                    ++idx1;
                }
                else
                {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin() + first);
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98, 69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41};
        Print(countSmaller(test));
    }
#endif /// DEBUG
};


}