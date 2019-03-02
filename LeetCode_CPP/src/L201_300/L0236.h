
#pragma once

#include "../Head.h"

namespace L0236
{


/// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (nullptr == root || root == p || root == q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return nullptr == left ? right : (nullptr == right ? left : root);
    }
};


}