
#pragma once

#include "../Head.h"

namespace L0173
{


/// https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator
{
public:
    BSTIterator(TreeNode* root)
    {
        FindLeft(root);
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode* top = st.top();
        st.pop();

        if (top->right != nullptr)
        {
            FindLeft(top->right);
        }

        return top->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }

private:

    void FindLeft(TreeNode* root)
    {
        for (TreeNode* p = root; p != nullptr; p = p->left)
        {
            st.push(p);
        }
    }

    stack<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


}