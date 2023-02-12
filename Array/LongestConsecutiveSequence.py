#Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
#You must write an algorithm that runs in O(n) time.

# O(N) time, O(N) memory for the created set
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nSet = set(nums)
        longest = 0
        for n in nSet:
            # start of a sequence
            if n-1 not in nSet:
                length = 1
                while(n + length in nSet):
                    length += 1
                longest = max(longest, length)
        return longest