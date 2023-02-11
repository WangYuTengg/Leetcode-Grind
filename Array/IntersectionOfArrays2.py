# Given two integer arrays nums1 and nums2, return an array of their intersection.
# Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


# O(MlogM + NlogN) time complexity 
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        i = j = 0
        ans = []
        while (i < len(nums1) and j < len(nums2)):
            if (nums1[i] < nums2[j]):
                i += 1
            elif (nums1[i] > nums2[j]):
                j += 1
            else: 
                ans.append(nums1[i])
                i += 1
                j += 1
        return ans
    
# O(M + N) time complexity
