#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "ListNode.h"
using namespace std;

class Leetcode0023
{
public:
    ListNode * mergeKLists(vector<ListNode*>& lists) {
        ListNode *pCurrent = new ListNode(0);
        ListNode *pHead = pCurrent;
        int Length = lists.size();
        while (true) {
            // find min
            bool isFind = false;
            int minIndex = -1;
            int min = INT_MAX;
            for (int i = 0; i < Length; ++i) {
                ListNode *tmp = lists[i];
                if (tmp && tmp->val < min) {
                    min = tmp->val;
                    minIndex = i;
                    isFind = true;
                }
            }

            if (isFind) {
                ListNode *tmp = lists[minIndex];
                pCurrent->next = tmp;
                pCurrent = pCurrent->next;
                lists[minIndex] = tmp->next;
            }
            else {
                break;
            }
        }

        return pHead->next;
    }
};