/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rets;
        if (nums.size() < 4) return rets;
        std::sort(nums.begin(), nums.end());
        int left, right;
        int sum;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                left = j + 1;
                right = nums.size() - 1;
                while (left < right) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) rets.push_back({nums[i], nums[j], nums[left], nums[right]});
                    if (sum <= target) do {++left;} while (left < right && nums[left] == nums[left-1]);
                    if (sum >= target) do {--right;} while(left < right && nums[right] == nums[right+1]);
                }
            }
        }
        return rets;
    }
};

int main() {
    Solution sln;
    vector<int> nums({1, 0, -1, 0, -2, 2});
    auto rets = sln.fourSum(nums, 0);
    for (auto& ret : rets) {
        printf("[%d, %d, %d, %d]\n", ret[0], ret[1], ret[2], ret[3]);
    }
    return 0;
}
