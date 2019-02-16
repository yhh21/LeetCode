
#pragma once

#include "../Head.h"

namespace L0142
{


/// https://leetcode.com/problems/word-break-ii/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return nullptr;
        }

        ListNode *slow = head, *fast = head, *entry = head;

        for (; nullptr != fast && nullptr != fast->next;)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                for (; slow != entry;)
                {
                    slow = slow->next;
                    entry = entry->next;
                }

                return entry;
            }
        }

        return nullptr;
    }
};


}