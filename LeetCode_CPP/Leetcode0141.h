#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
#include "ListNode.h"
using namespace std;

class Leetcode0141
{
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (true) {
            if (fast == nullptr) {
                return false;
            }

            fast = fast->next;
            if (fast == nullptr) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
    }
};