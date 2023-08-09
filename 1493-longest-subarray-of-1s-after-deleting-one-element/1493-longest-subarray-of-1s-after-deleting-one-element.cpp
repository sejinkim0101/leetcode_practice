// sol 1 - GPT4

#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int left = 0, zero_count = 0, max_length = 0;

        for (int right = 0; right < nums.size(); right++) {
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
            max_length = std::max(max_length, right - left);
        }

        return max_length;
    }
};
