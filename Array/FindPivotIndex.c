/**
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <stdio.h>

// initial solution
int pivotIndex(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++){
        int sumLeft = 0;
        int sumRight = 0;
        for (int j = 0; j < i; j++){
            sumLeft += nums[j];
        }
        for (int k = i+1; k < numsSize; k++){
            sumRight += nums[k];
        }
        printf("sumLeft: %d, sumRight: %d\n", sumLeft, sumRight);
        if (sumLeft == sumRight) return i;
    }
    return -1;
}
 
// slightly cleaner

int pivotIndex(int* nums, int numsSize){
    int sum = 0, left_sum = 0;
   
    for(int i=0; i<numsSize; i++){
        sum += nums[i];
    }
    for(int i=0; i<numsSize; i++){
        if(left_sum == sum-nums[i]-left_sum){
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}
