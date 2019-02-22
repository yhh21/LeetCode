
#pragma once

#include "../Head.h"

namespace L0199
{


/// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ret;
        Recursive(root, ret, 1);

        return ret;
    }

    void Recursive(TreeNode* root, vector<int> &ret, int deep)
    {
        if (nullptr == root)
        {
            return;
        }

        if (ret.size() < deep)
        {
            ret.push_back(root->val);
        }

        Recursive(root->right, ret, deep + 1);
        Recursive(root->left, ret, deep + 1);
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3, -1, 5, -1, 4};
        Print(rightSideView(Vector2TreeNode(test)));
    }
#endif /// DEBUG
};


}