/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rets;
        if (nums.size() < 3) return rets; 
        std::sort(nums.begin(), nums.end());
        int left, right;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) return rets;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    rets.push_back({nums[i], nums[left], nums[right]});
                }
                if (sum <= 0) {
                    do {++left;} while(left < right && nums[left] == nums[left-1]);
                }
                if (sum >= 0) {
                    do {--right;} while(left < right && nums[right] == nums[right+1]);    
                }
            }
        }
        return rets;
    }
};

int main() {
    Solution sln;
    vector<int> nums({-1, 0, 1, 2, -1, -4});
    vector<vector<int>> rets = sln.threeSum(nums);
    for (auto& item : rets) {
        printf("[%d, %d, %d]\n", item[0], item[1], item[2]);
    }
    return 0;
}
