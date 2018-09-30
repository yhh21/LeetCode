#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0111
{
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + (left < right ? left : right);
    }
};