
#pragma once

#include "../Head.h"

namespace L0187
{


/// https://leetcode.com/problems/repeated-dna-sequences/
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        const int Length = s.size();
        if (Length < 11)
        {
            return {};
        }

        unordered_set<int> words1;
        unordered_set<int> words2;

        vector<int> vec(26, 0);
        vec['C' - 'A'] = 1;
        vec['G' - 'A'] = 2;
        vec['T' - 'A'] = 3;

        int val = 0;
        for (int i = 0; i < 10; ++i)
        {
            // first value
            val = val << 2;
            val = val | vec[s[i] - 'A'];
        }
        words1.insert(val);

        vector<string> ret;
        for (int i = 10; i < Length; ++i)
        {
            val &= ~(3 << 18);
            val = val << 2;
            val = val | vec[s[i] - 'A'];
            if (words1.count(val))
            {
                if (!words2.count(val))
                {
                    words2.insert(val);
                    ret.push_back(s.substr(i - 9, 10));
                }
            }
            else
            {
                words1.insert(val);
            }

        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        Print(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
    }
#endif /// DEBUG
};


}