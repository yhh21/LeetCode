
#pragma once

#include "../Head.h"

namespace L0134
{


/// https://leetcode.com/problems/gas-station/
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        const int Length = gas.size();
        for (int i = 0; i < Length; ++i)
        {
            gas[i] -= cost[i];
        }

        for (int i = 0; i < Length; ++i)
        {
            if (gas[i] < 0)
            {
                continue;
            }

            for (int j = (i + 1) % Length, tmp = gas[i]; j != i; j = (j + 1) % Length)
            {
                tmp += gas[j];
                if (tmp < 0)
                {
                    // go to next index
                    do
                    {
                        ++i;
                    }
                    while (i < Length && gas[i] >= 0);

                    goto GOTO_FAIL;
                }
            }

            return i;

        GOTO_FAIL:
            ;// ;
        }

        return -1;
    }

#ifdef DEBUG
    void Test()
    {
        vector<int> test = {3, 3, 4};
        vector<int> test1 = {3, 4, 4};
        Print(canCompleteCircuit(test, test1));
    }
#endif /// DEBUG
};


}