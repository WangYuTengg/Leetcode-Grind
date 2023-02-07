/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

// brute force - O(n^2) time
#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * result = malloc(sizeof(int) * 2);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++){
        for (int j = i+1; j<numsSize; j++){
            int sum = nums[i] + nums[j];
            if (sum == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}

/**
 * Python Code for O(n) time using map
 * # traverse list twice -> O(n) time complexity , O(1) lookup
    class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]] 
*/