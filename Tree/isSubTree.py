# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Naive approach, O(s * t)
class Solution:
    def isMatch(self, s, t):
        if not(s and t): # if both not null
            return s is t # does s and t match

        # recursively call on branches
        return (s.val == t.val and 
                self.isMatch(s.left, t.left) and 
                self.isMatch(s.right, t.right))

    def isSubtree(self, s, t):
        if self.isMatch(s, t): return True # case where tree matches
        if not s: return False # case where s is empty
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t) # recursively call on subtrees