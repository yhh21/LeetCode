
#pragma once

#include "../Head.h"

namespace L0102
{


/// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        RecursiveTree(root, ret);

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