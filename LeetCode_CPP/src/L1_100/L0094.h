
#pragma once

#include "../Head.h"

namespace L0094
{


/// https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;

        stack<TreeNode *> m_stack;
        TreeNode *p_cur = root;

        for (; nullptr != p_cur || !m_stack.empty();)
        {
            if (nullptr != p_cur)
            {
                m_stack.push(p_cur);
                p_cur = p_cur->left;
            }
            else
            {
                TreeNode *p_tmp = m_stack.top();
                m_stack.pop();

                ret.push_back(p_tmp->val);
                p_cur = p_tmp->right;
            }
        }

        return ret;
    }
};


}