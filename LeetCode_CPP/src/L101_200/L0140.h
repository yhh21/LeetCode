
#pragma once

#include "../Head.h"

namespace L0140
{


/// https://leetcode.com/problems/word-break-ii/
class Solution
{
public:
    unordered_map<string, vector<string>> cache;

    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> m_set;
        for (string str : wordDict)
        {
            m_set.insert(str);
        }

        return Recursive(s, m_set);
    }

    vector<string> Recursive(const string &s, const unordered_set<string>& m_set)
    {
        if (cache.count(s))
        {
            return cache[s]; //take from memory
        }

        vector<string> ret;
        if (m_set.count(s))
        {
            //a whole string is a word
            ret.push_back(s);
        }

        const int Length = s.size();
        for (int i = 1; i < Length; ++i)
        {
            string word = s.substr(i);
            if (m_set.count(word))
            {
                string pre = s.substr(0, i);
                vector<string> pre_v = Combine(word, Recursive(pre, m_set));
                ret.insert(ret.end(), pre_v.begin(), pre_v.end());
            }
        }

        cache[s] = ret; //memorize
        return ret;
    }

    vector<string> Combine(const string &word, vector<string> pre_v)
    {
        const int Length = pre_v.size();
        for (int i = 0; i < Length; ++i)
        {
            pre_v[i] += " " + word;
        }

        return pre_v;
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test = {"cat", "cats", "and", "sand", "dog"};
        Print(wordBreak("catsanddog", test));
    }
#endif /// DEBUG
};


}