
#pragma once

#include "../Head.h"

namespace L0082
{


/// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (nullptr != head)
        {
            ListNode *p_head = new ListNode(0);
            p_head->next = head;

            bool is_duplicate = false;
            ListNode *p_pre_pre = p_head;
            ListNode *p_pre = p_pre_pre->next;
            ListNode *p_cur = p_pre->next;

            for (; p_cur != nullptr;)
            {
                if (p_pre->val == p_cur->val)
                {
                    is_duplicate = true;
                    p_pre->next = p_cur->next;
                }
                else
                {
                    if (is_duplicate)
                    {
                        is_duplicate = false;
                        p_pre_pre->next = p_cur;
                    }
                    else
                    {
                        p_pre_pre = p_pre;
                    }
                }

                p_pre = p_cur;
                p_cur = p_cur->next;
            }

            if (is_duplicate)
            {
                p_pre_pre->next = p_cur;
            }

            return p_head->next;
        }
        else
        {
            return nullptr;
        }
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 1, 1, 2, 3, 3, 4, 4, 5, 5};

        Print(deleteDuplicates(Vector2ListNode(test)));
    }
#endif /// DEBUG
};


}