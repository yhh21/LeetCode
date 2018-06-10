#pragma once

#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Leetcode0027 {
public:
    static int removeElement(vector<int>& nums, int val) {
        int Lenght = nums.size();

        int i = 0, j = Lenght - 1;
        for (; i <= j; --j) {
            if (nums[j] != val) {
                for (; i <= j; ++i) {
                    if (nums[i] == val) {
                        nums[i++] = nums[j];
                        break;
                    }
                }
            }
        }

        return i;
    }
};
