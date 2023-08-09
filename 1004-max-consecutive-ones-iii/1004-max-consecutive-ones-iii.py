class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = 0
        max_length = 0

        # Iterate through the array to expand the window
        for right in range(len(nums)):
            # If the current element is 0, we need to flip it
            if nums[right] == 0:
                k -= 1

            # If k goes negative, we need to shrink the window
            while k < 0:
                # If the left element is 0, we need to revert the flip
                if nums[left] == 0:
                    k += 1
                left += 1

            # Update the maximum length of consecutive 1's
            max_length = max(max_length, right - left + 1)

        return max_length
