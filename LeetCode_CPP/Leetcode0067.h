#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0067
{
public:
    static string addBinary(string a, string b) {
        int Length1 = a.length();
        int Length2 = b.length();

        int tag = 0;
        int i = 0;

        for (; i < Length1 && i < Length2; ++i) {
            int tmp = a[Length1 - i - 1] - '0' + b[Length2 - i - 1] - '0' + tag;
            a[Length1 - i - 1] = tmp % 2 + '0';
            tag = tmp / 2;
        }

        if (i == Length1) {
            for (; i < Length2; ++i) {
                int tmp = b[Length2 - i - 1] - '0' + tag;
                a = to_string(tmp % 2) + a;
                tag = tmp / 2;
            }
        }
        else {
            for (; i < Length1; ++i) {
                int tmp = a[Length1 - i - 1] - '0' + tag;
                a[Length1 - i - 1] = tmp % 2 + '0';
                tag = tmp / 2;
            }
        }

        while (tag > 0) {
            a = to_string(tag % 2) + a;
            tag = tag / 2;
        }

        return a;
    }
};