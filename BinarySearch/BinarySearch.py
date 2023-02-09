class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums.sort()
        high = len(nums) - 1
        low = 0
        # O(log n) time 
        while (low <= high):
            mid = (low + high) // 2 

            if (nums[mid] == target): return mid

            # target is on right side of mid
            elif (target > nums[mid]): low = mid + 1

            # target is on left side of mid
            else: high = mid - 1
            
        return -1