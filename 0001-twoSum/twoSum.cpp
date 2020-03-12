/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdio.h>

#include <vector>
using std::vector;

// force
// T(n) = O(n^2)
// S(n) = O(1)
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sub;
        int size = nums.size();
        int i,j;
        for (i = 0; i < size-1; ++i) {
            sub = target - nums[i];
            for (j = i+1; j < size; ++j) {
                if (nums[j] == sub) {
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>();
    }
};
*/

// HashMap
// T(n) = O(n)
// S(n) = O(n)
#include <map>
using std::map;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value => index
        map<int, int> vis;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            int sub = target - nums[i];
            iter = vis.find(sub);
            if (iter != vis.end()) {
                return vector<int>{iter->second, i};
            }
            vis[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution sln;
    vector<int> results = sln.twoSum(nums, target);
    if (results.size() == 0) {
        printf("Not Found\n");
    }
    else {
        printf("results: [%d,%d]\n", results[0], results[1]);
    }
    return 0;
}
