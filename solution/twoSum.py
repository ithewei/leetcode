class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i in range(len(nums)):
            sub = target - nums[i]
            if sub in dic:
                return [dic[sub], i]
            dic[nums[i]] = i
        