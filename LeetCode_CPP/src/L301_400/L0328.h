
#pragma once

#include "../Head.h"

namespace L0328
{


/// https://leetcode.com/problems/odd-even-linked-list/
class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (nullptr == head)
        {
            return nullptr;
        }

        ListNode *odd_head = head, *even_head = head->next;
        for (ListNode *tmp_node = even_head; nullptr != tmp_node && nullptr != tmp_node->next;)
        {
            odd_head->next = odd_head->next->next;
            tmp_node->next = tmp_node->next->next;
            odd_head = odd_head->next;
            tmp_node = tmp_node->next;
        }
        odd_head->next = even_head;

        return head;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 3, 4, 5};
        Print(oddEvenList(Vector2ListNode(test)));
    }
#endif /// DEBUG
};


}