#include <math.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    // Initialize the sum for the first k elements
    double sum = 0;
    for(int i = 0; i < k; i++) {
        sum += nums[i];
    }
    
    // Store the initial sum as the maximum average
    double max_avg = sum / k;

    // Slide the window over the array
    for(int i = k; i < numsSize; i++) {
        // Add the current element and subtract the first element of the previous window
        sum += nums[i] - nums[i - k];
        // Update the maximum average if the new average is greater
        max_avg = fmax(max_avg, sum / k);
    }

    return max_avg;
}
