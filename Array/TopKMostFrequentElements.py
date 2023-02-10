#Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for n in nums:
            count[n] = count.get(n, 0) + 1
        freq = [ [] for i in range(len(nums) + 1)] # 0, 1, ..., n  -> need to include 0 so + 1

        for num, count in count.items():
            freq[count].append(num)
        
        res = []
        for n in range(len(freq)-1, 0, -1): # start from the back (most freq) and go in reverse order
            for i in freq[n]:
                res.append(i)
    
                if len(res) == k:
                    return res