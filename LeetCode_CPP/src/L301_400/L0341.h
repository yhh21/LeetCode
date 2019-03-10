
#pragma once

#include "../Head.h"

namespace L0341
{

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

/// https://leetcode.com/problems/flatten-nested-list-iterator/
class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; --i)
        {
            _stack.push(nestedList[i]);
        }
    }

    int next()
    {
        int ret = _stack.top().getInteger();
        _stack.pop();

        return ret;
    }

    bool hasNext()
    {
        while (!_stack.empty())
        {
            NestedInteger cur = _stack.top();
            if (cur.isInteger())
            {
                return true;
            }

            _stack.pop();
            vector<NestedInteger> nestedList = cur.getList();
            for (int i = nestedList.size() - 1; i >= 0; --i)
            {
                _stack.push(nestedList[i]);
            }
        }

        return false;
    }

private:
    stack<NestedInteger> _stack;
};


}