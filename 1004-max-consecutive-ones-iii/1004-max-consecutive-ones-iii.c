// sol1- GPT4

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, max_length = 0;

    // Iterate through the array to expand the window
    for (int right = 0; right < numsSize; right++) {
        // If the current element is 0, we need to flip it
        if (nums[right] == 0) {
            k--;
        }

        // If k goes negative, we need to shrink the window
        while (k < 0) {
            // If the left element is 0, we need to revert the flip
            if (nums[left] == 0) {
                k++;
            }
            left++;
        }

        // Update the maximum length of consecutive 1's
        max_length = right - left + 1 > max_length ? right - left + 1 : max_length;
    }

    return max_length;
}
