
#pragma once

#include "../Head.h"

namespace L0116
{


/// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (nullptr == root)
        {
            return;
        }

        while (nullptr != root->left)
        {
            TreeLinkNode *p = root;
            while (nullptr != p)
            {
                p->left->next = p->right;
                if (nullptr != p->next)
                {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            root = root->left;
        }
    }
};


}