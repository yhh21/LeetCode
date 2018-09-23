#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Leetcode0012
{
public:
    // better solution
    map<int, string> mapRoman = { {1000, "M"}, { 900, "CM" },
    { 500, "D" },{ 400, "CD" },{ 100, "C" },{ 90, "XC" },
    { 50, "L" },{ 40, "XL" },{ 10, "X" },{ 9, "IX" },
    { 5, "V" },{ 4, "IV" },{ 1, "I" }};

    string intToRoman(int num) {
        string res;

        auto it = mapRoman.rbegin();
        auto end = mapRoman.rend();
        while (it != end) {
            while (num >= it->first) {
                num -= it->first;
                res += it->second;
            }
            ++it;
        }

        return res;
    }
};