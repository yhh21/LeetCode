
#pragma once

#include "../Head.h"

namespace L0144
{


/// https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        PreorderTraversal(root, ret);

        return ret;
    }

    void PreorderTraversal(TreeNode* root, vector<int> &ret)
    {
        if (nullptr == root)
        {
            return;
        }

        ret.push_back(root->val);
        PreorderTraversal(root->left, ret);
        PreorderTraversal(root->right, ret);
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {1, -1, 2, 3};

        Print(preorderTraversal(Vector2TreeNode(test1)));
    }
#endif /// DEBUG
};


}