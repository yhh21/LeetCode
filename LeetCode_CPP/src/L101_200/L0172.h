#pragma once

#include "../Head.h"

namespace L0172 {
    class Solution
    {
    public:
        int trailingZeroes(int n) {
            return n <= 0 ? 0 : (n / 5 + trailingZeroes(n / 5));
        }
    };
}