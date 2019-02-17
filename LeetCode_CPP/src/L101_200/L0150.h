
#pragma once

#include "../Head.h"

namespace L0150
{


/// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        unordered_map<string, std::function<int(int, int)>> map =
        {
        {"+", [](int a, int b) {
            return a + b;
        }},
        {"-", [](int a, int b)
        {
            return a - b;
        }},
        {"*", [](int a, int b)
        {
            return a * b;
        }},
        {"/", [](int a, int b)
        {
            return a / b;
        }}
        };

        std::stack<int> stack;
        for (string& s : tokens)
        {
            if (!map.count(s))
            {
                stack.push(stoi(s));
            }
            else
            {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }

        return stack.top();
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test1 = {"2", "1", "+", "3", "*"};

        Print(evalRPN(test1));
    }
#endif /// DEBUG
};


}