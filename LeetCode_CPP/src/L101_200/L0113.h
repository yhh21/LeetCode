
#pragma once

#include "../Head.h"

namespace L0113
{


/// https://leetcode.com/problems/path-sum-ii/
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> ret;
        vector<int> tmp;
        RecursiveTree(root, ret, tmp, sum);

        return ret;
    }

    void RecursiveTree(TreeNode* root, vector<vector<int>> &ret, vector<int> &tmp, const int &sum)
    {
        if (nullptr == root)
        {
            return;
        }

        tmp.push_back(root->val);
        // left node
        if (nullptr == root->left && nullptr == root->right)
        {
            if (0 == sum - root->val)
            {
                ret.push_back(tmp);
            }
        }
        else
        {
            RecursiveTree(root->left, ret, tmp, sum - root->val);
            RecursiveTree(root->right, ret, tmp, sum - root->val);
        }
        tmp.pop_back();
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
        Print(pathSum(Vector2TreeNode(test), 22));
    }
#endif /// DEBUG
};


}