
#pragma once

#include "../Head.h"

namespace L0380
{


/// https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (uo_map.find(val) != uo_map.end())
        {
            return false;
        }

        nums.push_back(val);
        uo_map[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (uo_map.find(val) == uo_map.end())
        {
            return false;
        }

        int last = nums.back();
        uo_map[last] = uo_map[val];
        nums[uo_map[val]] = last;
        nums.pop_back();
        uo_map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> uo_map;
};


}