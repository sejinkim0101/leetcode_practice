// Sol1 - GPT4

int longestSubarray(int* nums, int numsSize) {
    int left = 0, zero_count = 0, max_length = 0;

    for (int right = 0; right < numsSize; right++) {
        // If the current element is 0, increment the zero_count
        if (nums[right] == 0) {
            zero_count++;
        }

        // If there are more than one 0's, shrink the window
        while (zero_count > 1) {
            if (nums[left] == 0) {
                zero_count--;
            }
            left++;
        }

        // Update the maximum length of consecutive 1's (subtracting one for deletion)
        max_length = right - left > max_length ? right - left : max_length;
    }

    return max_length;
}
