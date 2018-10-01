#pragma once

#include "../Head.h"

namespace L0034 {
    class Solution
    {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int Length = nums.size();

            int start = 0;
            int end = Length - 1;
            bool isFind = false;

            for (; start <= end;) {
                int mid = (start + end) / 2;
                if (nums[mid] == target) {
                    isFind = true;
                    for (int _end = mid; start <= _end;) {
                        int _mid = (start + _end) / 2;
                        nums[_mid] == target ? _end = _mid - 1 : start = _mid + 1;
                    }
                    for (int _start = mid; _start <= end;) {
                        int _mid = (_start + end) / 2;
                        nums[_mid] == target ? _start = _mid + 1 : end = _mid - 1;
                    }
                    break;
                }
                else {
                    nums[mid] < target ? start = mid + 1 : end = mid - 1;
                }
            }

            vector<int> res;
            isFind ? (res.push_back(start), res.push_back(end)) : (res.push_back(-1), res.push_back(-1));
            return res;
        }


        void Test() {
            vector<int> test;

            test.push_back(5);
            test.push_back(7);
            test.push_back(7);
            test.push_back(8);
            test.push_back(8);
            test.push_back(10);

            searchRange(test, 6);
        }
    };
}