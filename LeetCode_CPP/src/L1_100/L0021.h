#pragma once

#include "../Head.h"

namespace L0021 {
    class Solution {
    public:
        static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;

            ListNode* p_head;
            ListNode* p_curNode;
            l1->val < l2->val ? (p_head = l1, l1 = l1->next) : (p_head = l2, l2 = l2->next);
            p_curNode = p_head;
            for (; l1 != nullptr && l2 != nullptr;) {
                l1->val < l2->val ? (p_curNode->next = l1, l1 = l1->next) : (p_curNode->next = l2, l2 = l2->next);
                p_curNode = p_curNode->next;
            }

            p_curNode->next = (l1 == nullptr ? l2 : l1);

            return p_head;
        }
    };
}