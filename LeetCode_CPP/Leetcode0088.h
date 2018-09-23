#pragma once

#include <string>
#include <vector>
#include <math.h>
#include "ListNode.h"
using namespace std;

class Leetcode0088
{
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int LENGTH = m + n;
        int m1 = m - 1;
        int n1 = n - 1;

        for (int i = LENGTH - 1; i >= 0; --i)
            if (m1 >= 0 && n1 >= 0) {
                nums1[i] = nums1[m1] >= nums2[n1] ? nums1[m1--] : nums2[n1--];
            }
            else {
                nums1[i] = m1 >= 0 ? nums1[m1--] : nums2[n1--];
            }
    }
};  