
#pragma once

#include "../Head.h"

namespace L0203
{


/// https://leetcode.com/problems/remove-linked-list-elements/
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* p_head = new ListNode(0);
        p_head->next = head;

        for (ListNode *p_cur = p_head->next, *p_pre = p_head; nullptr != p_cur;)
        {
            if (p_cur->val == val)
            {
                p_pre->next = p_cur->next;
            }
            else
            {
                p_pre = p_cur;
            }
            p_cur = p_cur->next;
        }

        return p_head->next;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {6, 2, 6, 3, 4, 5, 6};
        Print(removeElements(Vector2ListNode(test), 6));
    }
#endif /// DEBUG
};


}