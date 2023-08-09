# SOL1 - GPT4

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # Initialize the sum for the first k elements
        sum_k = sum(nums[:k])
        
        # Store the initial sum as the maximum average
        max_avg = sum_k / k

        # Slide the window over the array
        for i in range(k, len(nums)):
            # Add the current element and subtract the first element of the previous window
            sum_k += nums[i] - nums[i - k]
            # Update the maximum average if the new average is greater
            max_avg = max(max_avg, sum_k / k)

        return max_avg
