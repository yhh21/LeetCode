
#pragma once

#include "../Head.h"

namespace L0138
{


/// https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        RandomListNode *p_head, *l1, *l2;
        for (l1 = head; l1 != nullptr; l1 = l1->next)
        {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }

        p_head = head->random;
        for (l1 = head; l1 != nullptr; l1 = l1->next)
        {
            // new node
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : nullptr;
        }

        for (l1 = head; l1 != nullptr; l1 = l1->next)
        {
            // new node
            l2 = l1->random;
            // Revert.
            // Random pointer of node with label -1 from the original list was modified.
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
        }

        return p_head;
    }
};


}