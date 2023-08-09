// Sol1 - GPT4

#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0, max_length = 0;

        // Iterate through the array to expand the window
        for (int right = 0; right < nums.size(); right++) {
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
            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;
    }
};
