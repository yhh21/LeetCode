
#pragma once

#include "../Head.h"

namespace L0128
{


/// https://leetcode.com/problems/word-ladder-ii/
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ret = 0;
        unordered_map<int, int> map;
        for (int n : nums)
        {
            if (map.find(n) == map.end())
            {
                auto it_left = map.find(n - 1);
                int left = (it_left != map.end()) ? it_left->second : 0;
                auto it_right = map.find(n + 1);
                int right = (it_right != map.end()) ? it_right->second : 0;

                // sum: length of the sequence n is in
                int sum = left + right + 1;
                map.insert(std::pair<int, int>(n, sum));

                // keep track of the max length 
                ret = (std::max)(ret, sum);

                // extend the length to the boundary(s)
                // of the sequence
                // will do nothing if n has no neighbors
                auto it_left_2 = map.find(n - left);
                if (it_left_2 != map.end())
                {
                    it_left_2->second = sum;
                }
                else
                {
                    map.insert(std::pair<int, int>(n - left, sum));
                }
                auto it_right_2 = map.find(n + right);
                if (it_right_2 != map.end())
                {
                    it_right_2->second = sum;
                }
                else
                {
                    map.insert(std::pair<int, int>(n + right, sum));
                }
            }
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {1, 2, 0, 1};
        Print(longestConsecutive(test));
    }
#endif /// DEBUG
};


}