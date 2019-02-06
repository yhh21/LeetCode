
#pragma once

#include "../Head.h"

namespace L0099
{


/// https://leetcode.com/problems/recover-binary-search-tree/
class Solution
{
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root)
    {
        Recursive(root);
        std::swap(first->val, second->val);
    }

    void Recursive(TreeNode* root)
    {
        if (nullptr == root)
        {
            return;
        }

        Recursive(root->left);
        if (nullptr == first && prev->val >= root->val)
        {
            first = prev;
        }
        if (nullptr != first && prev->val >= root->val)
        {
            second = root;
        }
        prev = root;
        Recursive(root->right);
    }
};


}