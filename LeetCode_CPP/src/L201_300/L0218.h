
#pragma once

#include "../Head.h"

namespace L0218
{


/// https://leetcode.com/problems/the-skyline-problem/
class Solution
{
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {

        // Step 1:
        multimap<int, int> coords;
        for (const vector<int> & building : buildings)
        {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        // Step 2:
        multiset<int> heights = {0};
        map<int, int> corners;
        for (const pair<int, int> & p : coords)
        {
            if (p.second > 0)
            {
                heights.insert(p.second);
            }
            else
            {
                heights.erase(heights.find(-p.second));
            }
            int cur_y = *heights.rbegin();
            corners[p.first] = cur_y;
        }

        // Step 3:
        std::function<bool(pair<int, int> l, pair<int, int> r)> eq2nd =
            [](pair<int, int> l, pair<int, int> r)
        {
            return l.second == r.second;
        };
        vector<pair<int, int>> results;
        unique_copy(corners.begin(), corners.end(),
            back_insert_iterator<vector<pair<int, int>>>(results), eq2nd);
        return results;
    }

#ifdef DEBUG
    void Test()
    {
        vector<vector<int>> test = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
        getSkyline(test);
    }
#endif /// DEBUG
};


}