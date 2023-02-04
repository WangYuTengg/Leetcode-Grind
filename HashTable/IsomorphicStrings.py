# https://www.youtube.com/watch?v=7yF-U1hLEqQ
# hashmap time complexity O(1)
# space complexity -> 2 strings -> O(2n) == O(n)

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapST, mapTS = {}, {}

        for i in range(len(s)):
            c1 = s[i] #char1 from string s
            c2 = t[i] #char2 from string t
            #check mapping
            if (( (c2 in mapTS and mapTS[c2] != c1)) or (c1 in mapST and mapST[c1] != c2)): 
                return False
            
            #if not in mapping, add to mapping
            mapST[c1] = c2
            mapTS[c2] = c1

        return True