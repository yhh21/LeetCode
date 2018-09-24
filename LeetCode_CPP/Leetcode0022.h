#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "ListNode.h"
using namespace std;

class Leetcode0022
{
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        recursive(n, "", 0, 0);

        return res;
    }

    void recursive(int n, string str, int left, int right) {
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }

        if (left < n) {
            recursive(n, str + "(", left + 1, right);
        }

        if (right < left) {
            recursive(n, str + ")", left, right + 1);
        }
    }
};