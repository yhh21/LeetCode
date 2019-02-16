
#pragma once

#include "../Head.h"

namespace L0145
{


/// https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        PostorderTraversal(root, ret);

        return ret;
    }

    void PostorderTraversal(TreeNode* root, vector<int> &ret)
    {
        if (nullptr == root)
        {
            return;
        }

        PostorderTraversal(root->left, ret);
        PostorderTraversal(root->right, ret);
        ret.push_back(root->val);
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {1, -1, 2, 3};

        Print(postorderTraversal(Vector2TreeNode(test1)));
    }
#endif /// DEBUG
};


}