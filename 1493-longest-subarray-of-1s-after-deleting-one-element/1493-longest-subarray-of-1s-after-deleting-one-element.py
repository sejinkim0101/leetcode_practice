# Sol1 - GPT4

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        zero_count = 0
        max_length = 0

        for right in range(len(nums)):
            # If the current element is 0, increment the zero_count
            if nums[right] == 0:
                zero_count += 1
            
            # If there are more than one 0's, shrink the window
            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1

            # Update the maximum length of consecutive 1's (subtracting one for deletion)
            max_length = max(max_length, right - left)

        return max_length
