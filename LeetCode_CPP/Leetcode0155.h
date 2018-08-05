#pragma once

#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;

class MinStack {
public:
    long long min = INT_MIN;
    stack<long long> p_numStack;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (p_numStack.empty()) {
            p_numStack.push(0);
            min = x;
        }
        else {
            p_numStack.push(x - min);
            if (x < min) {
                min = x;
            }
        }
    }

    void pop() {
        int Length = p_numStack.size();
        if (!p_numStack.empty()) {
            long long tmp = p_numStack.top();
            p_numStack.pop();

            if (tmp < 0) {
                min -= tmp;
            }
        }
    }

    int top() {
        if (!p_numStack.empty()) {
            long long tmp = p_numStack.top();

            return min + (tmp < 0 ? 0 : tmp);
        }

        return INT_MIN;
    }

    int getMin() {
        return min;
    }
};