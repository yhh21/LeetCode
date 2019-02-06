
#pragma once

#include "../Head.h"

namespace L0098
{


/// https://leetcode.com/problems/validate-binary-search-tree/
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        if (nullptr == root)
        {
            return true;
        }

        std::stack<TreeNode *> _stack;
        TreeNode *p_pre = nullptr;
        while (nullptr != root || !_stack.empty())
        {
            while (nullptr != root)
            {
                _stack.push(root);
                root = root->left;
            }

            root = _stack.top();
            _stack.pop();

            if (nullptr != p_pre && root->val <= p_pre->val)
            {
                return false;
            }

            p_pre = root;
            root = root->right;
        }

        return true;
    }
};


}