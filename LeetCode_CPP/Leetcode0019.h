#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "ListNode.h"
using namespace std;

class Leetcode0019
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

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return mHead->next;
    }
};