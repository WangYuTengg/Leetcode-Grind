// brute force O(n^3)
int maxSubArray(int* nums, int numsSize){
    int result = -999999;
    for (int start = 0; start < numsSize; start++){
        for (int end = start; end < numsSize; end++){
            int sum = 0;
            for (int i = start; i <= end; i++){
                sum += nums[i];
            }
            if (sum > result) result = sum;

        }
    }
    return result;
}

// slight optimisation O(n^2)
int maxSubArray(int* nums, int numsSize){
    int result = -999999;
    for (int start = 0; start < numsSize; start++){
        int sum = 0;
        for (int end = start; end < numsSize; end++){
            sum += nums[end];
            if (sum > result) result = sum;
        }
    }
    return result;
}

// sliding window - linear solution O(n)
int maxSubArray(int* nums, int numsSize){
    int result = nums[0];
    int curSum = 0;
    for(int i = 0 ; i < numsSize; i++){
        if (curSum < 0) curSum = 0;
        curSum += nums[i];
        if (curSum > result) result = curSum;
    }
    return result;
}