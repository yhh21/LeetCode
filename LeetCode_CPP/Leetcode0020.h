#pragma once

#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Leetcode0020 {
public:
    static bool isValid(string s) {
        static int tag[128] {0};
        tag['('] = -1;
        tag[')'] = 1;
        tag['['] = -2;
        tag[']'] = 2;
        tag['{'] = -3;
        tag['}'] = 3;

        vector<int> vec;

        auto cstr = s.c_str();
        int Length = s.length();
        for (int i = 0; i < Length; ++i) {
            char c = cstr[i];
            if (tag[c] < 0) {
                vec.push_back(tag[c]);
            }
            else{
                if (vec.size() == 0) return false;

                int tmp = vec.back();
                if (tmp + tag[c] != 0) return false;

                vec.pop_back();
            }
        }

        return vec.size() == 0;
    }
};