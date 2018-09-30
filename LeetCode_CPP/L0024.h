#pragma once

#include "Head.h"

class Solution
{
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* res = head->next;
        head->next = swapPairs(res->next);
        res->next = head;

        return res;
    }
};