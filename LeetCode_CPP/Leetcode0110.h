#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0110
{
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int diff = GetHeightByTree(root->left) - GetHeightByTree(root->right);

        return ((diff <= 1) && (diff >= -1)) && isBalanced(root->left) && isBalanced(root->right);
    }

    int GetHeightByTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = GetHeightByTree(root->left);
        int rightHeight = GetHeightByTree(root->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
};