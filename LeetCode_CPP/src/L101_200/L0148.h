
#pragma once

#include "../Head.h"

namespace L0148
{


/// https://leetcode.com/problems/sort-list/
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode *slow = head, *fast = head->next;

        for (; nullptr != fast && nullptr != fast->next;)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = slow->next;
        slow->next = nullptr;

        return Merge(sortList(head), sortList(head2));
    }

    ListNode * Merge(ListNode *head1, ListNode *head2)
    {
        ListNode *p_head = new ListNode(0);
        ListNode *p_tmp = p_head;

        for (; nullptr != head1 && nullptr != head2;)
        {
            if (head1->val < head2->val)
            {
                p_tmp->next = head1;
                head1 = head1->next;
            }
            else
            {
                p_tmp->next = head2;
                head2 = head2->next;
            }

            p_tmp = p_tmp->next;
        }


        if (nullptr != head1)
        {
            p_tmp->next = head1;
        }
        else
        {
            p_tmp->next = head2;
        }

        return p_head->next;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test1 = {4, 2, 1, 3};

        Print(sortList(Vector2ListNode(test1)));
    }
#endif /// DEBUG
};


}