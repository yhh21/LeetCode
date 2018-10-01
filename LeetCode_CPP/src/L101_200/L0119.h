#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0119
{
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.insert(res.cend(), 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                int sum = res[j - 1] + res[j];
                if (i > j) {
                    res[j] = sum;
                }else{
                    res.insert(res.cend(), sum);
                }
            }

            if (i != 0) {
                res.insert(res.cend(), 1);
            }
        }

        return res;
    }
};