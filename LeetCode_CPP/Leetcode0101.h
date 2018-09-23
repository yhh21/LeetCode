#pragma once


#include <string>
#include <vector>
#include <cmath>
#include "TreeNode.h"
using namespace std;

class Leetcode0101
{
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return IsEqualTree(root->left, root->right);
    }

    bool IsEqualTree(TreeNode* left, TreeNode* right) {
        if ((left == nullptr && right == nullptr)) {
            return true;
        }

        if (left == nullptr || right == nullptr) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }
        else {
            return IsEqualTree(left->left, right->right) && IsEqualTree(left->right, right->left);
        }
    }
};