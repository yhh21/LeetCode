#pragma once


#include <string>
#include <vector>
#include <cmath>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;

class Leetcode0172
{
public:
    int trailingZeroes(int n) {
        return n <= 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};