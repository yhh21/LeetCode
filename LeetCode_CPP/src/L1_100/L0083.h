
#pragma once

#include "../Head.h"

namespace L0083
{


class Solution
{
public:
    static ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) return head;
        ListNode* pre = head;
        ListNode* p = pre->next;
        while (p != nullptr)
        {
            if (pre->val == p->val)
            {
                pre->next = p->next;
                //delete p;
            }
            else
                pre = p;

            p = pre->next;
        }

        return head;
    }
};


}