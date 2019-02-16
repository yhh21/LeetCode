
#pragma once

#include "../Head.h"

namespace L0143
{


/// https://leetcode.com/problems/reorder-list/
class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return;
        }

        ListNode *p1 = head, *p2 = head->next;

        for (; nullptr != p2 && nullptr != p2->next;)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* p_head_2 = p1->next;
        p1->next = nullptr;

        p2 = p_head_2->next;
        p_head_2->next = nullptr;

        for (; nullptr != p2;)
        {
            p1 = p2->next;
            p2->next = p_head_2;

            p_head_2 = p2;
            p2 = p1;
        }

        for (p1 = head, p2 = p_head_2; nullptr != p1;)
        {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
    }
};


}