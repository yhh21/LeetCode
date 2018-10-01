#pragma once

#include "../Head.h"

namespace L0030 {
    class Solution
    {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> res;
            int wordsLength = words.size();
            if (wordsLength == 0) return res;

            map<string, int> wordMap;
            for (int i = 0; i < wordsLength; ++i) {
                ++wordMap[words[i]];
            }

            int wordLength = words[0].size();

            map<string, int> tmpWordMap;
            int Length = wordsLength * wordLength;
            int sLength = s.size() - Length + 1;
            for (int i = 0; i < sLength; ++i) {
                tmpWordMap.clear();
                bool isFind = true;
                for (int j = 0; j < Length; j += wordLength) {
                    string subStr = s.substr(j + i, wordLength);
                    auto it = wordMap.find(subStr);
                    if (it == wordMap.end() || (++tmpWordMap[subStr]) > it->second) {
                        isFind = false;
                        break;
                    }
                }

                if (isFind) {
                    res.push_back(i);
                }
            }

            return res;
        }

        void Test() {
            vector<string> strVec;
            strVec.push_back("foo");
            strVec.push_back("bar");
            findSubstring("barfoothefoobarman", strVec);
        }
    };
}