#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0112
{
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        int diff = sum - root->val;
        if (diff == 0 && (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        return hasPathSum(root->left, diff) || hasPathSum(root->right, diff);
    }
};