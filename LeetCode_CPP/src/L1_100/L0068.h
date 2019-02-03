
#pragma once

#include "../Head.h"

namespace L0068
{


/// https://leetcode.com/problems/text-justification/
class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        const int Length = words.size();
        vector<string> justifiedText;

        for (int i = 0, j; i < Length; i = j)
        {
            int lineWordsLength = 0;
            for (j = i; j < Length && lineWordsLength + words[j].size() + (j - i) <= maxWidth
                ; lineWordsLength += words[j].size(), ++j);

            string line = words[i];
            for (int k = i + 1; k < j; ++k)
            {
                int paddingSize = 1;
                if (j < Length)
                {
                    paddingSize = (maxWidth - lineWordsLength) / (j - k)
                        + ((maxWidth - lineWordsLength) % (j - k) != 0 ? 1 : 0);
                    lineWordsLength += paddingSize;
                }

                line.append(paddingSize, ' ').append(words[k]);
            }

            line.append(maxWidth - line.size(), ' ');
            justifiedText.push_back(line);
        }

        return justifiedText;
    }
};


}