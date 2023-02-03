/**
Given an array nums. 
We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

// initial solution
int* runningSum(int* nums, int numsSize, int* returnSize){
    int * resultArray = malloc(sizeof(int) * numsSize);
    int sum;
   
    for (int i = 0; i < numsSize; i++){
        sum = 0;
        for (int j = 0; j <= i; j++){
            sum += nums[j];
        }
        resultArray[i] = sum;
    }
    *returnSize = numsSize;
    return resultArray;
}

// second solution , slightly cleaner
int* runningSum(int* nums, int numsSize, int* returnSize){
    for (int i = 1; i < numsSize; i++){
        nums[i] += nums[i-1];
    }
    *returnSize = numsSize;
    return nums;
}