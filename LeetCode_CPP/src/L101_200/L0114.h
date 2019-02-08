
#pragma once

#include "../Head.h"

namespace L0114
{


/// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
class Solution
{
public:
    void flatten(TreeNode* root)
    {
        RecursiveTree(root);
    }

    TreeNode* RecursiveTree(TreeNode* root)
    {
        if (nullptr == root || (nullptr == root->left && nullptr == root->right))
        {
            return root;
        }
        else
        {
            TreeNode *left_tail = RecursiveTree(root->left);
            TreeNode *right_tail = nullptr != root->right ? RecursiveTree(root->right) : left_tail;

            if (nullptr != left_tail)
            {
                left_tail->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            return right_tail;
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 5, 3, 4, -1, 6};
        flatten(Vector2TreeNode(test));
    }
#endif /// DEBUG
};


}