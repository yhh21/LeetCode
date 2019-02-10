
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
        unordered_set<string> hash_set;
        for (string str : wordList)
        {
            hash_set.insert(str);
        }
        hash_set.insert(beginWord);

        vector<vector<string>> ret;
        unordered_map<string, vector<string>> nodeNeighbors;// Neighbors for every node
        unordered_map<string, int> distance;// Distance of every node from the beginWord node
        vector<string> solution;

        bfs(beginWord, endWord, hash_set, nodeNeighbors, distance);
        dfs(beginWord, endWord, hash_set, nodeNeighbors, distance, solution, ret);
        return ret;
    }

    // BFS: Trace every node's distance from the beginWord node (level by level).
    void bfs(string &beginWord, string &endWord, unordered_set<string> &hash_set,
        unordered_map<string, vector<string>> &nodeNeighbors, unordered_map<string, int> &distance)
    {
        for (string str : hash_set)
        {
            vector<string> tmp;
            nodeNeighbors.insert(pair<string, vector<string>>(str, tmp));
        }

        std::queue<string> queue;
        queue.push(beginWord);
        distance.insert(pair<string, int>(beginWord, 0));

        bool is_find = false;
        while (!queue.empty())
        {
            const int Length = queue.size();
            for (int i = 0; i < Length; i++)
            {
                string cur = queue.front();
                queue.pop();
                const int curDistance = distance.find(cur)->second;
                vector<string> neighbors = getNeighbors(cur, hash_set);

                auto &neighbors_vec = nodeNeighbors.find(cur)->second;
                for (string neighbor : neighbors)
                {
                    neighbors_vec.push_back(neighbor);
                    if (distance.find(neighbor) == distance.end())
                    {
                        // Check if visited
                        distance.insert(pair<string, int>(neighbor, curDistance + 1));

                        if (endWord == neighbor)// Found the shortest path
                        {
                            is_find = true;
                        }
                        else
                        {
                            queue.push(neighbor);
                        }
                    }
                }
            }

            if (is_find)
            {
                break;
            }
        }
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

    // DFS: output all paths with the shortest distance.
    void dfs(string &cur, string &endWord, unordered_set<string> &hash_set,
        unordered_map<string, vector<string>> &nodeNeighbors, unordered_map<string, int> &distance,
        vector<string> &solution, vector<vector<string>> &ret)
    {
        solution.push_back(cur);
        if (endWord == cur)
        {
            ret.push_back(solution);
        }
        else
        {
            const int next_distance = distance.find(cur)->second + 1;
            for (string next : nodeNeighbors.find(cur)->second)
            {
                if (next_distance == distance.find(next)->second)
                {
                    dfs(next, endWord, hash_set, nodeNeighbors, distance, solution, ret);
                }
            }
        }
        solution.pop_back();
    }

#ifdef DEBUG
    void Test()
    {
        vector<string> test = {"hot", "dot", "dog", "lot", "log", "cog"};
        Print(findLadders("hit", "cog", test));
    }
#endif /// DEBUG
};


}