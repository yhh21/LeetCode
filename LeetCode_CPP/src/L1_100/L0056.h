#pragma once

#include "../Head.h"

namespace L0056
{
    /// https://leetcode.com/problems/merge-intervals/
    class Solution
    {
    public:
        vector<Interval> merge(vector<Interval>& intervals)
        {
            const int Length = intervals.size();
            vector<Interval> ret;
            if (0 < Length)
            {
                sort(intervals.begin(), intervals.end(), [](const Interval &left, const Interval &right)
                {
                    return left.start < right.start;
                });

                ret.push_back(intervals[0]);
                for (int left = 0, right = 1; right < Length; ++right)
                {
                    if (ret[left].end >= intervals[right].start)
                    {
                        ret[left].end = std::max(ret[left].end, intervals[right].end);
                    }
                    else
                    {
                        ret.push_back(intervals[right]);
                        ++left;
                    }
                }
            }

            return ret;
        }
    };
}