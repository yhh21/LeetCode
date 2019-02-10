
#pragma once

#include "../Head.h"

namespace L0127
{


/// https://leetcode.com/problems/word-ladder/
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> hash_set;
        for (string str : wordList)
        {
            hash_set.insert(str);
        }
        hash_set.insert(beginWord);

        unordered_map<string, int> distance;// Distance of every node from the beginWord node
        distance.insert(pair<string, int>(beginWord, 1));

        std::queue<string> queue;
        queue.push(beginWord);

        while (!queue.empty())
        {
            string cur = queue.front();
            queue.pop();
            const int curDistance = distance.find(cur)->second;

            for (string neighbor : getNeighbors(cur, hash_set))
            {
                if (distance.find(neighbor) == distance.end())
                {
                    if (endWord == neighbor)// Found the shortest path
                    {
                        return curDistance + 1;
                    }
                    else
                    {
                        // Check if visited
                        distance.insert(pair<string, int>(neighbor, curDistance + 1));
                        queue.push(neighbor);
                    }
                }
            }
        }

        return 0;
    }

    // Find all next level nodes.
    vector<string> getNeighbors(string &node, unordered_set<string> &hash_set)
    {
        vector<string> ret;
        const int Length = node.size();
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            for (int i = 0; i < Length; ++i)
            {
                if (node[i] == ch)
                {
                    continue;
                }
                char old_ch = node[i];
                node[i] = ch;
                if (hash_set.find(node) != hash_set.end())
                {
                    ret.push_back(node);
                }
                node[i] = old_ch;
            }
        }

        return ret;
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test = {"hot", "dot", "dog", "lot", "log", "cog"};
        Print(ladderLength("hit", "cog", test));
    }
#endif /// DEBUG
};


}