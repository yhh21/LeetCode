#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
    {}
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

TreeNode* Vector2TreeNode(const vector<int> &nums)
{
    const int Length = nums.size();

    TreeNode *p_head = nullptr;
    if (0 < Length)
    {
        p_head = new TreeNode(nums[0]);
        TreeNode *p = p_head;

        queue<TreeNode *> _queue;
        _queue.push(p);

        int index = 1;
        while (!_queue.empty() && index < Length)
        {
            TreeNode *cur_node = _queue.front();
            _queue.pop();

            TreeNode *left_node = nums[index] != -1 ? new TreeNode(nums[index]) : nullptr;
            ++index;
            TreeNode *right_node = nums[index] != -1 ? new TreeNode(nums[index]) : nullptr;
            ++index;

            cur_node->left = left_node;
            cur_node->right = right_node;

            if (nullptr != left_node)
            {
                _queue.push(left_node);
            }
            if (nullptr != right_node)
            {
                _queue.push(right_node);
            }
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


void RecursiveTree(TreeNode* root, vector<vector<int>> &ret, const int &deep = 0)
{
    if (nullptr == root)
    {
        return;
    }

    if (deep == ret.size())
    {
        vector<int> tmp;
        ret.push_back(tmp);
    }

    ret[deep].push_back(root->val);

    RecursiveTree(root->left, ret, deep + 1);
    RecursiveTree(root->right, ret, deep + 1);
}

void Print(TreeNode *tree)
{
    vector<vector<int>> ret;
    RecursiveTree(tree, ret);

    Print(ret);
}