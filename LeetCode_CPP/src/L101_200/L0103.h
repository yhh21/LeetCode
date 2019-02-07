
#pragma once

#include "../Head.h"

namespace L0103
{


/// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        RecursiveTree(root, ret);

        const int Length = ret.size();
        for (int i = 1; i < Length; i = i + 2)
        {
            std::reverse(ret[i].begin(), ret[i].end());
        }

        return ret;
    }

    void RecursiveTree(TreeNode* root, vector<vector<int>> &ret, const int &deep = 0)
    {
        if (nullptr == root)
        {
            return;
        }

        if (deep == ret.size())
        {
            vector<int> tmp;
            ret.push_back(tmp);
        }

        ret[deep].push_back(root->val);

        RecursiveTree(root->left, ret, deep + 1);
        RecursiveTree(root->right, ret, deep + 1);
    }
};


}