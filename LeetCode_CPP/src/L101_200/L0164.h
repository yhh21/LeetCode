
#pragma once

#include "../Head.h"

namespace L0164
{


/// https://leetcode.com/problems/maximum-gap/
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        const int Length = nums.size();
        if (Length < 2)
        {
            return 0;
        }
        // get the max and min value of the array
        int min = nums[0];
        int max = nums[0];
        for (int i : nums)
        {
            min = (std::min)(min, i);
            max = (std::max)(max, i);
        }
        // the minimum possibale gap, ceiling of the integer division
        int gap = (int)std::ceil(1.0f * (max - min) / (Length - 1));
        vector<int> bucketsMIN(Length - 1, INT_MAX); // store the min value in that bucket
        vector<int> bucketsMAX(Length - 1, INT_MIN); // store the max value in that bucket

        // put numbers into buckets
        for (int i : nums)
        {
            if (i == min || i == max)
            {
                continue;
            }
            int idx = (i - min) / gap; // index of the right position in the buckets
            bucketsMIN[idx] = (std::min)(i, bucketsMIN[idx]);
            bucketsMAX[idx] = (std::max)(i, bucketsMAX[idx]);
        }
        // scan the buckets for the max gap
        int ret = INT_MIN;
        int previous = min;
        for (int i = 0; i < Length - 1; ++i)
        {
            if (bucketsMIN[i] == INT_MAX && bucketsMAX[i] == INT_MIN)
            {  // empty bucket
                continue;
            }
            // min value minus the previous value is the current gap
            ret = (std::max)(ret, bucketsMIN[i] - previous);
            // update previous bucket value
            previous = bucketsMAX[i];
        }
        ret = (std::max)(ret, max - previous); // updata the final max value gap
        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {4, 2, 5};
        Print(maximumGap(test));
    }
#endif /// DEBUG
};


}