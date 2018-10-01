#pragma once


#include <string>
#include <vector>
#include <math.h>
#include "TreeNode.h"
using namespace std;

class Leetcode0125
{
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;

        while (head < tail) {
            if (!(isalpha(s[head]) || isalnum(s[head]))) {
                ++head;
            } 
            else if(!(isalpha(s[tail]) || isalnum(s[tail]))) {
                --tail;
            }
            else if ((s[head] + 32 - 'a') % 32 != (s[tail] + 32 - 'a') % 32) {
                return false;
            }
            else {
                ++head;--tail;
            }
        }

        return true;
    }
};