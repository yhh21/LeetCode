
#pragma once

#include "../Head.h"

namespace L0129
{


/// https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution
{
public:
    int sumNumbers(TreeNode* root)
    {
        vector<int> root2leaf;
        int tmp = 0;

        RecursiveTree(root, root2leaf, tmp);

        tmp = 0;
        for (int n : root2leaf)
        {
            tmp += n;
        }

        return tmp;
    }

    void RecursiveTree(TreeNode *root, vector<int> &root2leaf, int &tmp)
    {
        if (nullptr == root)
        {
            return;
        }

        tmp = tmp * 10 + root->val;
        if (nullptr == root->left && nullptr == root->right)
        {
            root2leaf.push_back(tmp);
        }
        else
        {
            RecursiveTree(root->left, root2leaf, tmp);
            RecursiveTree(root->right, root2leaf, tmp);
        }
        tmp /= 10;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {4, 9, 0, 5, 1};
        Print(sumNumbers(Vector2TreeNode(test)));
    }
#endif /// DEBUG
};


}