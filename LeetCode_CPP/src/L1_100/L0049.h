#pragma once

#include "../Head.h"

namespace L0049
{
    /// https://leetcode.com/problems/group-anagrams/
    class Solution
    {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            const int Length = strs.size();

            vector<vector<int>> alpha_numbers;
            alpha_numbers.reserve(Length);

            for (int i = 0; i < Length; ++i)
            {
                vector<int> tmp_num;
                tmp_num.resize(26);

                string tmp = strs[i];
                int tmp_Length = tmp.size();
                for (int j = 0; j < tmp_Length; ++j)
                {
                    ++tmp_num[tmp[j] - 'a'];
                }

                alpha_numbers.push_back(tmp_num);
            }

            vector<vector<string>> ret;
            vector<int> ret_index;

            for (int i = 0; i < Length; ++i)
            {
                bool is_find = false;
                for (int j = 0; j < ret_index.size(); ++j)
                {
                    if (IsEquals(alpha_numbers[i], alpha_numbers[ret_index[j]]))
                    {
                        is_find = true;
                        ret[j].push_back(strs[i]);
                        break;
                    }
                }

                if (!is_find)
                {
                    vector<string> tmp;
                    tmp.push_back(strs[i]);

                    ret.push_back(tmp);
                    ret_index.push_back(i);
                }
            }

            return ret;
        }

        inline
            bool IsEquals(const vector<int> &a, const vector<int> &b)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (a[i] != b[i]) return false;
            }

            return true;
        }

    #ifdef DEBUG
        void Test()
        {
            vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

            Print(strs);

            auto ret = groupAnagrams(strs);

            Print(ret);
        }
    #endif /// DEBUG
    };
}