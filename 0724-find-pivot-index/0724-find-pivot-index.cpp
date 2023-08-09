//  sol1 - GPT4

#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);  // Total sum of the array
        int left_sum = 0;  // Sum of elements to the left of the current index

        // Iterate through the array to find the pivot index
        for (int idx = 0; idx < nums.size(); idx++) {
            // Check if the left sum equals the right sum (total_sum - left_sum - nums[idx])
            if (left_sum == total_sum - left_sum - nums[idx]) {
                return idx;
            }
            left_sum += nums[idx];
        }

        return -1;  // Return -1 if no pivot index found
    }
};
