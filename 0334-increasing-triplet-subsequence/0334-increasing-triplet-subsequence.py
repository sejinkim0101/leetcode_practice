# class Solution:
#     def increasingTriplet(self, nums: List[int]) -> bool:
        
#         ans = 'false'
        
#         n = len(nums)
        
#         for i in range(n):
#             for j in range(i+1, n):
#                 if nums[i] < nums[j] :
#                     for k in range(j+1, n):
#                         if nums[j] < nums[k]:
#                             ans = 'true'
        
#         return ans

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # Initialize two variables to store the minimum and second minimum values found so far.
        first_min = float('inf')
        second_min = float('inf')

        # Loop through the array to check each element
        for num in nums:
            # If the current number is smaller than the first minimum,
            # then update the first minimum.
            if num <= first_min:
                first_min = num
            # If the current number is between the first and second minimum,
            # then update the second minimum.
            elif num <= second_min:
                second_min = num
            # If the current number is greater than both the first and second minimum,
            # then we have found our increasing triplet subsequence.
            else:
                return True

        # If the loop finishes and we haven't returned True, then no such triplet exists.
        return False
