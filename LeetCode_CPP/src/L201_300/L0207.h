
#pragma once

#include "../Head.h"

namespace L0207
{


/// https://leetcode.com/problems/course-schedule/
class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        auto graph = MakeGraph(numCourses, prerequisites);
        auto degrees = CalculateIndegree(graph);

        for (int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for (; j < numCourses; ++j)
            {
                if (0 == degrees[j])
                {
                    break;
                }
            }
            if (j == numCourses)
            {
                return false;
            }

            degrees[j] = -1;
            for (int neigh : graph[j])
            {
                --degrees[neigh];
            }
        }

        return true;
    }

    vector<unordered_set<int>> MakeGraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);

        for (auto &pre : prerequisites)
        {
            graph[pre.second].insert(pre.first);
        }

        return graph;
    }

    vector<int> CalculateIndegree(vector<unordered_set<int>>& graph)
    {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
        {
            for (int neigh : neighbors)
            {
                ++degrees[neigh];
            }
        }

        return degrees;
    }

#ifdef DEBUG
    void Test()
    {
        vector<pair<int, int>> test = {{1, 0}};
        Print(canFinish(2, test));
    }
#endif /// DEBUG
};


}