# Given a string s, find the length of the longest substring without repeating characters.
#  O(n) time and space
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        length = 0
        for r in range(len(s)):
            # duplicates
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            length = max(r - l + 1, length)

        return length