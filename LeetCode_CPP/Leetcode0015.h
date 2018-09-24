#pragma once

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Leetcode0015
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> *tmp;
        const int Length = nums.size();

        for (int i = 0; i < Length - 2;) {
            if (nums[i] > 0) {
                break;
            }

            for (int j = i + 1, k = Length - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    tmp = new vector<int>();
                    tmp->push_back(nums[i]);
                    tmp->push_back(nums[j]);
                    tmp->push_back(nums[k]);
                    res.push_back(*tmp);
                    
                    do {
                        ++j;
                    } while (j < k && nums[j - 1] == nums[j]);
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
                else if (sum < 0) {
                    do {
                        ++j;
                    } while (j < k && nums[j - 1] == nums[j]);
                }
                else {
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }

            do {
                ++i;
            } while (i < Length - 2 && nums[i - 1] == nums[i]);
        }

        return res;
    }
};