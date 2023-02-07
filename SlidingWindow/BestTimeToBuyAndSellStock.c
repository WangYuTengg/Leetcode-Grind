/**
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

// brute force - O(N^2) time complexity
int maxProfit(int* prices, int pricesSize){
    int result = 0;
    for (int i = 0; i < pricesSize; i++){
        int temp = 0;
        for(int j = i+1; j < pricesSize; j++){
            temp = prices[j] - prices[i];
            if (temp > result) result = temp;
        }
    }
    return result;
}

// Sliding window - https://www.youtube.com/watch?v=1pkOgXD63yU
int maxProfit(int* prices, int pricesSize){
    int result = 0;
    int left = prices[0];
    for(int i = 1; i<pricesSize; i++){
        int right = prices[i];
        if (left > right){
            left = right;
        }
        int temp = right - left;
        if (temp > result) result = temp;
    }
    return result;
}