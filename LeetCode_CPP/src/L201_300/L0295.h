
#pragma once

#include "../Head.h"

namespace L0295
{


/// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder
{
public:

    void addNum(int num)
    {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        return small.size() > large.size()
            ? small.top()
            : (small.top() - large.top()) * 0.5f;
    }

private:
    priority_queue<long> small, large;
};


}