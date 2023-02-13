# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
# Find two lines that together with the x-axis form a container, such that the container contains the most water.
# Return the maximum amount of water a container can store.

# O(N) time
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # initialise left and right pointers
        l, r = 0 , len(height) - 1

        # to store result
        maxArea = 0

        # condition for one pass
        while l < r:
            maxArea = max(maxArea, min(height[l], height[r]) * (r-l) ) # r-l is base, min(height[l],height[r]) is the height
    
            if height[r] > height[l]:
                l += 1
            elif height[r] <= height[l]:
                r -= 1
        
        return maxArea