#pragma once

#include "../Head.h"

namespace L0061
{


/// https://leetcode.com/problems/rotate-list/
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (k <= 0 || nullptr == head) return head;

        int Length = 0;
        ListNode *p_start = head;
        for (;;)
        {
            ++Length;
            if (nullptr != p_start->next)
            {
                p_start = p_start->next;
            }
            else
            {
                p_start->next = head;
                break;
            }
        }

        if (1 < Length)
        {
            k = k % Length;
            if (0 != k)
            {
                k = Length - k - 1;
                p_start = head;
                for (int i = 0; i < k; ++i)
                {
                    p_start = p_start->next;
                }
            }
        }

        head = p_start->next;
        p_start->next = nullptr;

        return head;
    }

#ifdef DEBUG
    void Test()
    {
        ListNode* head = new ListNode(0);
        ListNode* p_start = head;
        for (int i = 1; i <= 5; ++i)
        {
            p_start->next = new ListNode(i);
            p_start = p_start->next;
        }

        Print(rotateRight(head->next, 2));
    }
#endif /// DEBUG
};


}