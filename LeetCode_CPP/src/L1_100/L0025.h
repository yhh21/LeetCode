#pragma once

#include "../Head.h"

namespace L0025
{
    class Solution
    {
    public:
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            int Length = 0;
            ListNode *pNode = head;
            for (; Length < k && pNode != nullptr; ++Length, pNode = pNode->next);

            if (Length < k) return head;

            ListNode *res = nullptr;
            ListNode *tail = head;
            for (int i = 0; i < k; ++i)
            {
                ListNode *tmp = head->next;
                head->next = res;
                res = head;
                head = tmp;
            }
            tail->next = reverseKGroup(pNode, k);

            return res;
        }
    };
}