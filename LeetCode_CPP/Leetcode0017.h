#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Leetcode0017
{
public:
    vector<string> res;
    vector<string> tree;
    int treeDeep;
    string strs[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(string digits) {
        int Length = digits.size();
        if (Length != 0) {
            res.clear();
            tree.clear();

            for (int i = 0; i < Length; ++i) {
                tree.push_back(strs[(int)(digits[i] - '2')]);
            }

            treeDeep = tree.size();
            traversePath(0, "");
        }

        return res;
    }

    void traversePath(int deep, string pre) {
        if (deep >= treeDeep) return;
        
        bool isTail = deep == treeDeep - 1;

        string currentStr = tree[deep];
        int Length = currentStr.size();
        for (int i = 0; i < Length; ++i) {
            string tmp = pre + currentStr[i];
            if (isTail) {
                res.push_back(tmp);
            }
            else {
                traversePath(deep + 1, tmp);
            }
        }
    }
};