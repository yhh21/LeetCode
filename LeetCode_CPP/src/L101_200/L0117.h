
#pragma once

#include "../Head.h"

namespace L0117
{


/// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        TreeLinkNode *p_head = nullptr; // p_head of the next level
        TreeLinkNode *p_pre = nullptr; // the leading node on the next level
        TreeLinkNode *p_cur = root;  // current node of current level

        while (nullptr != p_cur)
        {
            // iterate on the current level
            while (nullptr != p_cur)
            {
                // left child
                if (nullptr != p_cur->left)
                {
                    if (nullptr != p_pre)
                    {
                        p_pre->next = p_cur->left;
                    }
                    else
                    {
                        p_head = p_cur->left;
                    }
                    p_pre = p_cur->left;
                }
                // right child
                if (nullptr != p_cur->right)
                {
                    if (nullptr != p_pre)
                    {
                        p_pre->next = p_cur->right;
                    }
                    else
                    {
                        p_head = p_cur->right;
                    }
                    p_pre = p_cur->right;
                }
                // move to next node
                p_cur = p_cur->next;
            }

            // move to next level
            p_cur = p_head;
            p_head = nullptr;
            p_pre = nullptr;
        }
    }
};


}