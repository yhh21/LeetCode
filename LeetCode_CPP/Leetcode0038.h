#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0038
{
public:
    static string countAndSay(int n) {
        if (n <= 1) return "1";

        string tmp = countAndSay(n - 1);
        string res = "";

        char c = tmp[0];
        int sameNum = 1;
        int Length = tmp.length();


        for (int i = 1; i < Length; ++i) {
            char tmp_c = tmp[i];
            if (tmp_c != c) {
                res = res + to_string(sameNum) + c;

                c = tmp_c;
                sameNum = 0;
            }
            ++sameNum;
        }

        res = res + to_string(sameNum) + c;

        return res;
    }
};