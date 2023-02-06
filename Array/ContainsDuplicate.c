
#include <stdbool.h>
#include <stdio.h>

// brute force O(n^2)
bool containsDuplicate(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if (nums[j] == nums[i]) return true;
        }
    }
    return false;
}

