#You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
#Return the length of the longest substring containing the same letter you can get after performing the above operations.

# O(N) time
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0 
        count = {}
        l = 0
        maxf = 0

        # r - l + 1 is length of sliding window
        # maxf is the highest frequency of a character in the substring
        # if r - l + 1 - maxf is greater than k -> cannot replace all characters (that is not the maxf) to get repeats
        for r in range(len(s)):
            # update counter 
            count[s[r]] = count.get(s[r], 0) + 1
            maxf = max(maxf, count[s[r]]) # O(1) lookup for checking the count of s[r]

            # loop to ensure number of characters needed to replace does not exceed k 
            while (r - l + 1) - maxf > k:
                count[s[l]] -= 1
                l += 1 # decrease sliding window

            # update result
            res = max(r - l + 1, res)

        return res