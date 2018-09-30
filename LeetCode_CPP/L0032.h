#pragma once

#include "Head.h"

class Solution
{
public:
    int longestValidParentheses(string s) {
        int Length = s.length();
        if (Length == 0) return 0;

        int res = 0;
        int *dp = new int[Length]();

        for (int i = Length - 2; i >= 0; --i) {
            if (s[i] == '(') {
                int j = i + 1 + dp[i + 1];
                if (j < Length && s[j] == ')') {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < Length) {
                        dp[i] += dp[j + 1];
                    }
                }
            }
            res = res > dp[i] ? res : dp[i];
        }

        return res;
    }
};