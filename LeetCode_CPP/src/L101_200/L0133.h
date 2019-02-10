
#pragma once

#include "../Head.h"

namespace L0132
{


/// https://leetcode.com/problems/clone-graph/
class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (nullptr == node)
        {
            return nullptr;
        }

        if (copies.find(node) == copies.end())
        {
            copies[node] = new UndirectedGraphNode(node->label);
            for (UndirectedGraphNode* neighbor : node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return copies[node];
    }

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copies;
};


}