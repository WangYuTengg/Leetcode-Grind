/**
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

// O(N) time, O(1) space
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
   int last = m + n -1;
   
   // merge in reverse order
   while(m > 0 && n > 0){
       if (nums1[m-1] > nums2[n-1]){
           nums1[last] = nums1[m-1];
           m--;
       }
       else{
           nums1[last] = nums2[n-1];
           n--;
       }
       last--;
   }

    // append the rest of num2 elements into num1 
   while (n>0){
       nums1[last] = nums2[n-1];
       last--;
       n--;
   }
}