# Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hSet = {}
        for i in range(len(nums)):
            if (nums[i] in hSet) and abs(i - hSet[nums[i]]) <= k:
                return True
            hSet[nums[i]] = i
        return False