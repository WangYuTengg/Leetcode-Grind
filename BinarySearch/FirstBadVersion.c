#include <stdio.h>
#include <stdbool.h>

// O(logN) time
int firstBadVersion(long n) {
    long lo = 1;
    long hi = n;
    long result = -1;
    while (lo <= hi){
        long mid = (lo+hi) / 2;
        if (isBadVersion(mid) == true) {
            hi = mid - 1;
            result = mid;
        }
        else if (isBadVersion(mid) == false) lo = mid + 1;
    }
    return result;
}
