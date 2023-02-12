# O(n^2) time
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort() # O(nlogn) time

        for i, a in enumerate(nums):
            # duplicates
            if i > 0 and a == nums[i - 1]:
                continue

            # 2 pointer technique
            l, r= i + 1, len(nums) - 1
            while l < r:
                threeSum = a + nums[l] + nums[r] 
                
                # threeSum too great, need to decrement right pointer
                if threeSum > 0:
                    r -= 1

                # threeSum too small, need to increment left pointer
                elif threeSum < 0:
                    l += 1

                else: #threesum == 0  -> append to results
                    res.append([a, nums[l], nums[r]])
                    l += 1 #move left pointer 

                    #check for duplicates
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
        return res