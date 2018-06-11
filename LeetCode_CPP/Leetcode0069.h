#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0069
{
public:
    static int mySqrt(int x) {
        if (x < 2) return x;

        int left = 0;
        int right = x;
        int mid = x / 2;

        while (true) {
            if (1 <= x / mid / mid) {
                if (1 > x / (mid + 1) / (mid + 1)) {
                    return mid;
                }
                left = mid;
                mid = (right + mid) / 2;
            }
            else {
                right = mid;
                mid = (left + mid) / 2;
            }
        }
    }
};