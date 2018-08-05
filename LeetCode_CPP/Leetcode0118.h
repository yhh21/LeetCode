#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0118
{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp;
            tmp.insert(tmp.cend(), 1);

            for (int j = 1; j < i; ++j) {
                int sum = res[i - 1][j - 1] + res[i - 1][j];
                tmp.insert(tmp.cend(), sum);
            }

            if (i != 0) {
                tmp.insert(tmp.cend(), 1);
            }

            res.insert(res.cend(), tmp);
        }

        return res;
    }
};