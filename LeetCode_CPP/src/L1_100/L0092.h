
#pragma once

#include "../Head.h"

namespace L0092
{


/// https://leetcode.com/problems/reverse-linked-list-ii/
class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *p_head = new ListNode(0);
        p_head->next = head;

        ListNode *p_pre = p_head;
        for (int i = 0; i < m - 1; ++i)
        {
            p_pre = p_pre->next;
        }

        ListNode *p_cur = p_pre->next;
        for (int i = 0; i < n - m; ++i)
        {
            ListNode *p_tmp = p_cur->next;
            p_cur->next = p_tmp->next;
            p_tmp->next = p_pre->next;
            p_pre->next = p_tmp;
        }

        return p_head->next;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3, 4, 5};
        Print(reverseBetween(Vector2ListNode(test), 2, 4));
    }
#endif /// DEBUG
};


}