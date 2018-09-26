#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "ListNode.h"
using namespace std;

class Leetcode0025
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int Length = 0;
        ListNode *pNode = head;
        while (pNode != nullptr) {
            ++Length;
            pNode = pNode->next;
            if (Length >= k) break;
        }
        
        if (Length < k) return head;
        
        ListNode *res = nullptr;
        ListNode *tail = head;
        for (int i = 0; i < k; ++i) {
            ListNode *tmp = head->next;
            head->next = res;
            res = head;
            head = tmp;
        }
        tail->next = reverseKGroup(pNode, k);

        return res;
    }
};