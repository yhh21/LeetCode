#pragma once
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Leetcode0026 {
public:
    static int removeDuplicates(vector<int>& nums) {
        int Lenght = nums.size();
        if (Lenght == 0) return 0;

        int res = 1;

        int tmp = nums[0];
        for (int i = 1; i < Lenght; ++i) {
            if (nums[i] != tmp) {
                nums[res++] = nums[i];
                tmp = nums[i];
            }
        }

        return res;
    }
};