#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0)
    {}
    Interval(int s, int e) : start(s), end(e)
    {}
};


ListNode* Vector2ListNode(const vector<int> &nums)
{
    const int Length = nums.size();

    ListNode *p_head = nullptr;
    if (0 < Length)
    {
        p_head = new ListNode(nums[0]);
        ListNode *p = p_head;

        for (int i = 1; i < Length; ++i)
        {
            ListNode *pp = new ListNode(nums[i]);
            p->next = pp;
            p = p->next;
        }
    }

    return p_head;
}


template<typename T> inline
void Print(const T &val)
{
    cout << val;
}

template<typename T>
void Print(const vector<T> &nums)
{
    const int Length = nums.size();
    Print("[");
    for (int i = 0; i < Length; ++i)
    {
        Print(nums[i]);

        if (Length - 1 != i)
        {
            Print(", ");
        }
    }
    Print("]\n");
}

template<typename T>
void Print(const vector<vector<T>> &mm)
{
    const int Length = mm.size();
    for (int i = 0; i < Length; ++i)
    {
        const int tmp_Length = mm[i].size();

        Print("[");
        for (int j = 0; j < tmp_Length; ++j)
        {
            Print(mm[i][j]);

            if (tmp_Length - 1 != j)
            {
                Print(", ");
            }
        }
        Print("]\n");
    }
}


void Print(ListNode *list)
{
    ListNode *p = list;
    Print("[");
    for (; nullptr != p;)
    {
        Print(p->val);

        if (nullptr != p->next)
        {
            Print(", ");
        }

        p = p->next;
    }
    Print("]\n");
}