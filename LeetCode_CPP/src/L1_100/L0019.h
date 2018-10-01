#pragma once

#include "../Head.h"

namespace L0019 {
    class Solution
    {
    public:
        ListNode * removeNthFromEnd(ListNode* head, int n) {
            ListNode* mHead = new ListNode(0);
            mHead->next = head;
            ListNode* fast = mHead;
            ListNode* slow = mHead;

            for (int i = 0; i < n + 1; ++i) {
                fast = fast->next;
            }
            for (; fast != nullptr; fast = fast->next) {
                slow = slow->next;
            }

            slow->next = slow->next->next;

            return mHead->next;
        }
    };
}