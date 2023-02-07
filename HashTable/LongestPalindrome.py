# Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
# Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
#Time Complexity: O(N), wbere N is the length of s. We need to count each letter.


class Solution(object):
    def longestPalindrome(self, s):
        
        counts = {}
        odd_flag = False
        for char in s:  
            counts[char] = counts.get(char, 0) + 1

        result = 0
        for _, count in counts.items():
            if (count % 2 == 0):
                result += count
            else:
                odd_flag = True
                result += count - 1
        
        if (odd_flag == True):
             result += 1
        return result