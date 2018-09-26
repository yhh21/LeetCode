#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "ListNode.h"
using namespace std;

class Leetcode0024
{
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* tmp = head->next;
        head->next = swapPairs(tmp->next);
        tmp->next = head;

        return tmp;
    }
};