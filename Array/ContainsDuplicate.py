class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        #Creating a data structure to store each element in array we scan through
        hash_table = {}
        #Going through each element in array
        for p in range(len(nums)):
            if hash_table.get(nums[p]):
                return True
            else:
                hash_table[nums[p]] = True
        return False


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = dict()
        for num in nums:
            if num in hashset:
                return True
            hashset[num] = 1
        return False