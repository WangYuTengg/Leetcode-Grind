#Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#An input string is valid if:
#Open brackets must be closed by the same type of brackets.
#Open brackets must be closed in the correct order.
#very close bracket has a corresponding open bracket of the same type.

# O(n) time
class Solution:
    def isValid(self, s: str) -> bool:
        # case where string is odd
        if len(s) % 2 != 0: return False

        # create stack
        stck = []

        # iterate through the string
        for b in s:
            i = len(stck) - 1 # keep track of top of stack

            # open brackets, push to stack
            if b == "(" or b == "[" or b == "{":
                stck.append(b)
                continue
            
            # if close brackets
            elif (len(stck) == 0): return False
            elif (b == ")" and stck[i] == "(") or (b == "]" and stck[i] == "[") or (b == "}" and stck[i] == "{"):
                stck.pop(i)
                
            else:
                return False
        return (len(stck) == 0)

# using map
class Solution:
    def isValid(self, s: str) -> bool:
        Map = {")": "(", "]": "[", "}": "{"}
        stack = []

        for c in s:
            if c not in Map: # open brackets
                stack.append(c)
                continue
            if not stack or stack[-1] != Map[c]: 
                return False
            stack.pop()

        return not stack