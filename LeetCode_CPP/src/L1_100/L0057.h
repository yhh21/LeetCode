#pragma once

#include "../Head.h"

namespace L0057
{


/// https://leetcode.com/problems/insert-interval/
class Solution
{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        const int Length = intervals.size();
        vector<Interval> ret;

        int left, right;

        for (int i = 0, j = Length - 1;;)
        {
            if (i > j)
            {
                left = j;
                break;
            }

            int mid = (i + j) / 2;

            if (intervals[mid].start > newInterval.start)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }

        for (int i = 0, j = Length - 1;;)
        {
            if (i > j)
            {
                right = i;
                break;
            }

            int mid = (i + j) / 2;

            if (intervals[mid].end < newInterval.end)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }

        if (left >= 0 && intervals[left].end >= newInterval.start)
        {
            newInterval.start = intervals[left].start;
            --left;
        }

        if (right < Length && intervals[right].start <= newInterval.end)
        {
            newInterval.end = intervals[right].end;
            ++right;
        }

        for (int i = 0; i <= left; ++i)
        {
            ret.push_back(intervals[i]);
        }
        ret.push_back(newInterval);;
        for (int i = right; i < Length; ++i)
        {
            ret.push_back(intervals[i]);
        }

        return ret;
    }
};


}