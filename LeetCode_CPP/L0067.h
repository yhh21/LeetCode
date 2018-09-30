#pragma once

#include "Head.h"

class Solution
{
public:
    static string addBinary(string a, string b) {
        int aLength = a.length();
        int bLength = b.length();

        int tag = 0;
        int i = 0;

        for (; i < aLength && i < bLength; ++i) {
            int tmp = a[aLength - i - 1] - '0' + b[bLength - i - 1] - '0' + tag;
            a[aLength - i - 1] = tmp % 2 + '0';
            tag = tmp / 2;
        }

        if (i == aLength) {
            for (; i < bLength; ++i) {
                int tmp = b[bLength - i - 1] - '0' + tag;
                a = to_string(tmp % 2) + a;
                tag = tmp / 2;
            }
        }
        else {
            for (; i < aLength; ++i) {
                int tmp = a[aLength - i - 1] - '0' + tag;
                a[aLength - i - 1] = tmp % 2 + '0';
                tag = tmp / 2;
            }
        }

        for (; tag > 0; tag /= 2) {
            a += to_string(tag % 2);
        }

        return a;
    }
};