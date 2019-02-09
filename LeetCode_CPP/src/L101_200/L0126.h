
#pragma once

#include "../Head.h"

namespace L0126
{


/// https://leetcode.com/problems/word-ladder-ii/
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_set<string> _hash_set;
        for (auto str : wordList)
        {
            _hash_set.insert(str);
        }

        vector<vector<string>> ret;
        vector<string> tmp_vec;

        int min_len = INT_MAX;
        Recursive(beginWord, endWord, _hash_set, beginWord, tmp_vec, ret, min_len);

        for (int i = ret.size() - 1; i >= 0; --i)
        {
            if (ret[i].size() > min_len)
            {
                ret.erase(ret.begin() + i);
            }
        }

        return ret;
    }

    void Recursive(const string &beginWord, const string &endWord, const std::unordered_set<string> &_hash_set
        , string tmp_str, vector<string> &tmp_vec, vector<vector<string>> &ret
        , int &min_len)
    {
        static int Length = tmp_str.size();

        if (tmp_vec.size() > min_len - 2)
        {
            return;
        }

        for (int i = 0; i < Length; ++i)
        {
            char tmp_char = tmp_str[i];
            for (int j = 'a'; j <= 'z'; ++j)
            {
                tmp_str[i] = j;
                if (beginWord != tmp_str && _hash_set.find(tmp_str) != _hash_set.end())
                {
                    if (endWord == tmp_str)
                    {
                        vector<string> _tmp_vec;

                        _tmp_vec.insert(_tmp_vec.begin(), beginWord);
                        _tmp_vec.insert(_tmp_vec.end(), tmp_vec.begin(), tmp_vec.end());
                        _tmp_vec.push_back(endWord);

                        min_len = _tmp_vec.size();
                        ret.push_back(_tmp_vec);
                        return;
                    }
                    else if (!IsInVector(tmp_vec, tmp_str))
                    {
                        tmp_vec.push_back(tmp_str);
                        Recursive(beginWord, endWord, _hash_set, tmp_str, tmp_vec, ret, min_len);
                        tmp_vec.pop_back();
                    }
                }
            }
            tmp_str[i] = tmp_char;
        }
    }

    bool IsInVector(const vector<string> &ret, const string &str)
    {
        for (auto _str : ret)
        {
            if (_str == str)
            {
                return true;
            }
        }

        return false;
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test = {"most", "mist", "miss", "lost", "fist", "fish"};
        Print(findLadders("lost", "miss", test));
    }
#endif /// DEBUG
};


}