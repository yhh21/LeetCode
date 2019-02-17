
#pragma once

#include "../Head.h"

namespace L0149
{


/// https://leetcode.com/problems/(std::max)-points-on-a-line/
class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        const int Length = points.size();
        int ret = 0;
        for (int i = 0; i < Length; ++i)
        {
            int samePoint = 1;
            int overFlowSlope = 0;
            unordered_map<string, int> map;
            for (int j = i + 1; j < Length; ++j)
            {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    ++samePoint;
                }
                else if (points[i].x == points[j].x)
                {
                    ++overFlowSlope;
                }
                else
                {
                    int yDif = points[i].y - points[j].y;
                    int xDif = points[i].x - points[j].x;
                    int g = GenerateGCD(yDif, xDif);
                    yDif /= g;
                    xDif /= g;
                    if (yDif < 0)
                    {
                        yDif = -yDif;
                        xDif = -xDif;
                    }

                    ++map[to_string(yDif) + "," + to_string(xDif)];
                }
            }

            int localMax = overFlowSlope;
            for (auto &it : map)
            {
                localMax = (std::max)(localMax, it.second);
            }

            localMax += samePoint;
            ret = (std::max)(ret, localMax);
        }

        return ret;
    }

    int GenerateGCD(int a, int b)
    {
        if (0 == b)
        {
            return a;
        }
        
        return GenerateGCD(b, a % b);
    }

#ifdef DEBUG
    void Test()
    {
        vector<Point> test1 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};

        Print(maxPoints(test1));
    }
#endif /// DEBUG
};


}