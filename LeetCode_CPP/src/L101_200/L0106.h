
#pragma once

#include "../Head.h"

namespace L0106
{


/// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return RecursiveBuildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* RecursiveBuildTree(const vector<int>& inorder, const vector<int>& postorder
        , const int &in_start, const int &in_end, const int &post_start, const int &post_end)
    {
        if (post_start > post_end)
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[post_end]);
        int index = in_start;
        for (; index <= in_end; ++index)
        {
            if (inorder[index] == node->val)
            {
                break;
            }
        }

        node->left = RecursiveBuildTree(inorder, postorder, in_start, index - 1, post_start, post_start + index - in_start - 1);
        node->right = RecursiveBuildTree(inorder, postorder, index + 1, in_end, post_end - in_end + index, post_end - 1);

        return node;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {9, 3, 15, 20, 7};
        vector<int> test2 = {9, 15, 7, 20, 3};

        Print(buildTree(test1, test2));
    }
#endif /// DEBUG
};


}