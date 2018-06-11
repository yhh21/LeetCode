#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0053
{
public:
    static int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int tmp = nums[0];

        int Length = nums.size();

        for (int i = 1; i < Length; ++i) {
            tmp = tmp > 0 ? tmp : 0;

            if (tmp + nums[i] > 0) {
                tmp += nums[i];
                res = res > tmp ? res : tmp;
            }
            else
            {
                tmp = nums[i];
                res = res > nums[i] ? res : nums[i];
            }
        }

        return res;
    }
};