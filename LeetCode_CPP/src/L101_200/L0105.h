
#pragma once

#include "../Head.h"

namespace L0105
{


/// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return RecursiveBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode* RecursiveBuildTree(const vector<int>& preorder, const vector<int>& inorder
        , const int &pre_start, const int &pre_end, const int &in_start, const int &in_end)
    {
        if (pre_start > pre_end)
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[pre_start]);
        int index = in_start;
        for (; index <= in_end; ++index)
        {
            if (inorder[index] == node->val)
            {
                break;
            }
        }

        node->left = RecursiveBuildTree(preorder, inorder, pre_start + 1, pre_start + index - in_start, in_start, index - 1);
        node->right = RecursiveBuildTree(preorder, inorder, pre_end - in_end + index + 1, pre_end, index + 1, in_end);

        return node;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {3, 9, 20, 15, 7};
        vector<int> test2 = {9, 3, 15, 20, 7};

        Print(buildTree(test1, test2));
    }
#endif /// DEBUG
};


}