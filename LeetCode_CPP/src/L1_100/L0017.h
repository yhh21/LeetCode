#pragma once

#include "../Head.h"

namespace L0017 {
    class Solution
    {
    public:
        vector<string> res;
        vector<string> tree;
        int treeDeep;

        vector<string> letterCombinations(string digits) {
            res.clear();
            tree.clear();

            string strs[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

            int Length = digits.size();
            if (Length != 0) {
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
                isTail ? res.push_back(tmp) : traversePath(deep + 1, tmp);
            }
        }
    };
}