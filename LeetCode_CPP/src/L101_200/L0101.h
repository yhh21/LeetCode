#pragma once

#include "../Head.h"

namespace L0101
{
    class Solution
    {
    public:
        bool isSymmetric(TreeNode* root)
        {
            if (root == nullptr) return true;

            return IsEqualTree(root->left, root->right);
        }

        bool IsEqualTree(TreeNode* left, TreeNode* right)
        {
            if (left == nullptr && right == nullptr) return true;
            if (left == nullptr || right == nullptr) return false;

            if (left->val != right->val) return false;
            else return IsEqualTree(left->left, right->right) && IsEqualTree(left->right, right->left);
        }
    };
}