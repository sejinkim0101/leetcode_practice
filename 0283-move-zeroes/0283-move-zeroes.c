// C Sol1) - GPT4

void moveZeroes(int* nums, int numsSize){
    int j = 0; // Initialize a pointer j to track the position of the next non-zero element

    // Iterate through the array from the beginning to the end
    for(int i = 0; i < numsSize; i++) {
        // Check if the current element is not zero
        if(nums[i] != 0) {
            // If it's not zero, place the value at the current j-th position
            nums[j] = nums[i];

            // If i and j are not pointing to the same position, the moved element was a non-zero element
            // Replace the original i-th position with zero since it has been moved to j-th position
            if(i != j) {
                nums[i] = 0;
            }

            // Increment j to point to the next position where the next non-zero element should be placed
            j++;
        }
        // If the current element is zero, just continue the loop and move to the next element
    }
}

// SOL2) - Leetcode discussion

// https://leetcode.com/problems/move-zeroes/discuss/3278867/C-Solution-or-with-Follow-Up-Question