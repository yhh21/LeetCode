#pragma once

#include "../Head.h"

namespace L0043 {
    // https://leetcode.com/problems/multiply-strings/
    class Solution {
    public:
        string multiply(string num1, string num2) {
            int Length1 = num1.size();
            int Length2 = num2.size();

            int *pos = new int[Length1 + Length2]();

            for (int i = Length1 - 1; i >= 0; --i) {
                for (int j = Length2 - 1; j >= 0; --j) {
                    int mul = (num1[i] - '0')*(num2[j] - '0');
                    int index1 = i + j;
                    int index2 = index1 + 1;
                    int sum = mul + pos[index2];

                    pos[index1] += sum / 10;
                    pos[index2] = sum % 10;
                }
            }

            string res = "";
            for (int i = 0; i < Length1 + Length2; ++i) {
                if (res.size() != 0 || pos[i] != 0) {
                    res += (char)(pos[i] + '0');
                }
            }

            return res.size() != 0 ? res : "0";
        }

        void Test() {
            multiply("408", "5");
        }
    };
}