#pragma once

#include "Head.h"

class Solution
{
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

        long long _dividend = dividend;
        long long _divisor = divisor;
        if (_dividend < 0) _dividend = -_dividend;
        if (_divisor < 0) _divisor = -_divisor;
        if (_dividend < _divisor) return 0;

        long long res = 0;
        for (int i = 31; i >= 0; --i) {
            long long tmp = _divisor << i;
            if (_dividend >= tmp) {
                res += 1 << i;
                _dividend -= tmp;
            }
        }

        return (int)(sign ? res : -res);
    }
};