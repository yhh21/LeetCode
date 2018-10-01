#pragma once

#include <string>
#include <vector>
#include <math.h>
#include "ListNode.h"
using namespace std;

class Leetcode0083
{
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* pre = head;
        ListNode* p = pre->next;
        while (p != nullptr) {
            if (pre->val == p->val) {
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