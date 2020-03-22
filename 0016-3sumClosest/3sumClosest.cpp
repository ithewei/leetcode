/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define ABS(n) ((n) < 0 ? -(n) : (n))
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        std::sort(nums.begin(), nums.end());
        int minsub = nums[0] + nums[1] + nums[2] - target;
        int sum, sub, left, right;
        for (int i = 0; i < nums.size() - 2; ++i) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return target;
                sub = sum - target;
                if (ABS(sub) < ABS(minsub)) {
                    minsub = sub;
                }
                if (sub < 0) {
                    do {++left;} while (left < right && nums[left] == nums[left-1]);
                } else {
                    do {--right;} while (left < right && nums[right] == nums[right+1]);
                }
            }
        }
        return target + minsub;
    }
};

int main() {
    vector<int> nums({-1, 2, 1, -4});
    Solution sln;
    int ret = sln.threeSumClosest(nums, 1);
    printf("%d\n", ret);
    return 0;
}
