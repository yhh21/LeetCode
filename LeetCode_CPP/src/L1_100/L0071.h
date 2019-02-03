
#pragma once

#include "../Head.h"

namespace L0071
{


/// https://leetcode.com/problems/simplify-path/
class Solution
{
public:
    string simplifyPath(string path)
    {
        string tmp;
        vector<string> vec;
        stringstream ss(path);
        for (;getline(ss, tmp, '/');)
        {
            if (tmp.empty() || "." == tmp)
            {
                continue;
            }

            if (tmp == "..")
            {
                if (!vec.empty())
                {
                    vec.pop_back();
                }
            }
            else
            {
                vec.push_back(tmp);
            }
        }
        
        string ret = "";
        int Length = vec.size();
        for (int i = 0; i < Length; ++i)
        {
            ret += "/" + vec[i];
        }

        return ret.empty() ? "/" : ret;
    }
};


}