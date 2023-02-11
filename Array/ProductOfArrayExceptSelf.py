#Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
#The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
#You must write an algorithm that runs in O(n) time and without using the division operation.

# O(N) time
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # product except self -> prefix * postfix of a specific pos
        ans = [1] * len(nums)

        #insert prefixes
        prefix = 1
        for i in range(len(nums)):
            ans[i] = prefix
            prefix *= nums[i]

        #multiply postfixes with prefixes
        postfix = 1
        for i in range(len(nums)-1, -1, -1):
            ans[i] *= postfix
            postfix *= nums[i]

        return ans