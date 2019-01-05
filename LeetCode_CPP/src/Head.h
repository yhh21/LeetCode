#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

template<typename T> inline
void Print(const vector<T> &nums)
{
    const int Length = nums.size();
    cout << "[";
    for (int i = 0; i < Length; ++i)
    {
        cout << nums[i];

        if (Length - 1 != i)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

template<typename T> inline
void Print(const vector<vector<T>> &mm)
{
    const int Length = mm.size();
    for (int i = 0; i < Length; ++i)
    {
        const int tmp_Length = mm[i].size();

        cout << "[";
        for (int j = 0; j < tmp_Length; ++j)
        {
            cout << mm[i][j];

            if (tmp_Length - 1 != j)
            {
                cout << ", ";
            }
        }
        cout << "]\n";
    }
}