
#pragma once

#include "../Head.h"

namespace L0095
{


/// https://leetcode.com/problems/unique-binary-search-trees-ii/
class Solution
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (0 == n)
        {
            return {};
        }

        return GenerateTrees(1, n);
    }

    vector<TreeNode*> GenerateTrees(const int &start, const int &end)
    {
        vector<TreeNode*> ret;

        if (start > end)
        {
            ret.push_back(nullptr);
            return ret;
        }

        for (int i = start; i <= end; ++i)
        {
            auto left_sub_tree = GenerateTrees(start, i - 1);
            auto right_sub_tree = GenerateTrees(i + 1, end);

            for (auto &left_node : left_sub_tree)
            {
                for (auto &right_node : right_sub_tree)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_node;
                    root->right = right_node;
                    ret.push_back(root);
                }
            }
        }

        return ret;
    }
};


}