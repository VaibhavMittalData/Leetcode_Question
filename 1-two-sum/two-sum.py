class Solution(object):
    def twoSum(self, nums, target):
        seen = {}
        for i, num in enumerate(nums):
            rem = target - num
            if rem in seen:
                return [seen[rem], i]
            else:
                seen[num] = i
        return []
                
        