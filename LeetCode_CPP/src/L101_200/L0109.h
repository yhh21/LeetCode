
#pragma once

#include "../Head.h"

namespace L0109
{


/// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        return RecursiveBuildBSTree(head);
    }

    TreeNode* RecursiveBuildBSTree(ListNode* head, ListNode* tail = nullptr)
    {
        if (head == tail)
        {
            return nullptr;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail && fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode *node = new TreeNode(slow->val);
        node->left = RecursiveBuildBSTree(head, slow);
        node->right = RecursiveBuildBSTree(slow->next, tail);

        return node;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {-10, -3, 0, 5, 9};

        Print(sortedListToBST(Vector2ListNode(test)));
    }
#endif /// DEBUG
};


}