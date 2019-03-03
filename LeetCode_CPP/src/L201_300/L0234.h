
#pragma once

#include "../Head.h"

namespace L0234
{


/// https://leetcode.com/problems/palindrome-linked-list/
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != nullptr)
        {
            if (head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 1, 4, -1, 2};
        Print(isPalindrome(Vector2ListNode(test)));
    }
#endif /// DEBUG
};


}