#pragma once

#include "../Head.h"

namespace L0027
{
    class Solution
    {
    public:
        static int removeElement(vector<int>& nums, int val)
        {
            int Lenght = nums.size();

            int i = 0;
            for (int j = Lenght - 1; i <= j; --j)
            {
                if (nums[j] != val)
                {
                    for (; i <= j; ++i)
                    {
                        if (nums[i] == val)
                        {
                            nums[i++] = nums[j];
                            break;
                        }
                    }
                }
            }

            return i;
        }
    };
}