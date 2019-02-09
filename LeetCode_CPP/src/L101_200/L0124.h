
#pragma once

#include "../Head.h"

namespace L0124
{


/// https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int ret = INT_MIN;
        RecursiveTree(root, ret);

        return ret;
    }

    int RecursiveTree(TreeNode *root, int &ret)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int left_sum = (std::max)(RecursiveTree(root->left, ret), 0);
        int right_sum = (std::max)(RecursiveTree(root->right, ret), 0);

        int sum = left_sum + right_sum + root->val;
        if (sum > ret)
        {
            ret = sum;
        }

        return root->val + (std::max)(left_sum, right_sum);
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {-10, 9, 20, -1, -1, 15, 7};
        Print(maxPathSum(Vector2TreeNode(test)));
    }
#endif /// DEBUG
};


}