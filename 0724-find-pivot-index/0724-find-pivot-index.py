# sol1- GPT4

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums)  # Total sum of the array
        left_sum = 0  # Sum of elements to the left of the current index

        # Iterate through the array to find the pivot index
        for idx, num in enumerate(nums):
            # Check if the left sum equals the right sum (total_sum - left_sum - num)
            if left_sum == total_sum - left_sum - num:
                return idx
            left_sum += num

        return -1  # Return -1 if no pivot index found
