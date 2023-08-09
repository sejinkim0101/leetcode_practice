// sol1 - GPt4

int pivotIndex(int* nums, int numsSize) {
    int total_sum = 0;  // Total sum of the array
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }

    int left_sum = 0;  // Sum of elements to the left of the current index

    // Iterate through the array to find the pivot index
    for (int idx = 0; idx < numsSize; idx++) {
        // Check if the left sum equals the right sum (total_sum - left_sum - nums[idx])
        if (left_sum == total_sum - left_sum - nums[idx]) {
            return idx;
        }
        left_sum += nums[idx];
    }

    return -1;  // Return -1 if no pivot index found
}
