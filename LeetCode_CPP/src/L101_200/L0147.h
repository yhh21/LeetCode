
#pragma once

#include "../Head.h"

namespace L0147
{


/// https://leetcode.com/problems/insertion-sort-list/
class Solution
{
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (nullptr == head)
        {
            return nullptr;
        }

        ListNode * p_head = new ListNode(INT_MIN);
        p_head->next = head;

        for (ListNode *p_pre = head, *p_next = head->next; nullptr != p_next;)
        {
            if (p_pre->val > p_next->val)
            {
                ListNode *p_next_next = p_next->next;

                ListNode *p_tmp_pre = p_head, *p_tmp_next = p_head->next;
                for (; nullptr != p_tmp_next; p_tmp_pre = p_tmp_next, p_tmp_next = p_tmp_next->next)
                {
                    if (p_next->val < p_tmp_next->val)
                    {
                        p_next->next = p_tmp_next;
                        p_tmp_pre->next = p_next;

                        p_next = p_next_next;
                        p_pre->next = p_next;
                        goto GOTO_BREAK;
                    }
                }
            }

            p_pre = p_next;
            p_next = p_next->next;
        GOTO_BREAK:
            ;
        }

        return p_head->next;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {4, 2, 1, 3};

        Print(insertionSortList(Vector2ListNode(test1)));
    }
#endif /// DEBUG
};


}