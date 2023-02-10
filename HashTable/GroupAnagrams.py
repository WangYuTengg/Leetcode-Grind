#Given an array of strings strs, group the anagrams together. 
#You can return the answer in any order.
#An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


# O(m*n) time - m = length of strs, n = avg length of each string
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = {}
        # iterate through each string
        for s in strs:
            charCount = [0] * 26 # to count all the letters in one string

            # iterate through each char in string
            for c in s:
                # use ascii values to help increment the correct index 
                charCount[ord(c) - ord('a')] += 1
            
            # lists cannot be keys so change to tuple
            if (tuple(charCount) not in res):
                res[tuple(charCount)] = [s]
            else:
                res[tuple(charCount)].append(s)

        # return the lists
        return res.values()