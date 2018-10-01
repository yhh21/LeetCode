#pragma once

#include "../Head.h"

namespace L0023 {
    class Solution
    {
    public:
        ListNode * mergeKLists(vector<ListNode*>& lists) {
            int Length = lists.size();
            ListNode *pCurrent = new ListNode(0);
            ListNode *pHead = pCurrent;
            while (true) {
                // find min
                bool isFind = false;
                int minIndex = -1;
                int min = INT_MAX;
                for (int i = 0; i < Length; ++i) {
                    ListNode *tmp = lists[i];
                    if (tmp && tmp->val < min) {
                        min = tmp->val;
                        minIndex = i;
                        isFind = true;
                    }
                }

                if (isFind) {
                    ListNode *tmp = lists[minIndex];
                    pCurrent->next = tmp;
                    pCurrent = pCurrent->next;
                    lists[minIndex] = tmp->next;
                }
                else break;
            }

            return pHead->next;
        }
    };
}