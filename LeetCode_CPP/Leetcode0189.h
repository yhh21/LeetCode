#pragma once


#include <string>
#include <vector>
#include <cmath>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;

class Leetcode0189
{
public:
    void rotate(vector<int>& nums, int k) {
        int Length = nums.size();
        k = k % Length;

        int count = 0;
        for (int i = 1; i <= k; ++i){
            int target = k - i;
            int t = Length - i;
            int end = nums[t];

            while (t != target) {
                int tmp = (t - k + Length) % Length;
                nums[t] = nums[tmp];
                t = tmp;
                ++count;
            }

            nums[target] = end;
            ++count;
            if (count >= Length) break;
        }
    }
};