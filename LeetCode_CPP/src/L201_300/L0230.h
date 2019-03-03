
#pragma once

#include "../Head.h"

namespace L0230
{


/// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        return FindKthSmallest(root, k);
    }

    int FindKthSmallest(TreeNode* root, int &k)
    {
        if (nullptr != root)
        {
            int x = FindKthSmallest(root->left, k);

            if (0 == k)
            {
                return x;
            }
            else
            {
                --k;
                return 0 == k ? root->val : FindKthSmallest(root->right, k);
            }
        }

        return -1;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 1, 4, -1, 2};
        Print(kthSmallest(Vector2TreeNode(test), 1));
    }
#endif /// DEBUG
};


}