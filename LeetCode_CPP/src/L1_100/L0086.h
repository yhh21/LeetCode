
#pragma once

#include "../Head.h"

namespace L0086
{


/// https://leetcode.com/problems/partition-list/
class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (nullptr != head)
        {
            ListNode *p_low = new ListNode(0);
            ListNode *p_high = new ListNode(0);

            ListNode *p_low_head = p_low;
            ListNode *p_high_head = p_high;

            ListNode *p_start = head;

            for (; nullptr != p_start;)
            {
                if (p_start->val < x)
                {
                    p_low->next = p_start;
                    p_low = p_low->next;
                }
                else
                {
                    p_high->next = p_start;
                    p_high = p_high->next;
                }

                p_start = p_start->next;
            }

            p_low->next = p_high_head->next;
            p_high->next = nullptr;

            return p_low_head->next;
        }
        else
        {
            return nullptr;
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test =
        {1, 4, 3, 2, 5, 2};

        Print(partition(Vector2ListNode(test), 3));
    }
#endif /// DEBUG
};


}