class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        

        n = max(nums)

        for i in range(len(nums)):
            if nums[i] == n:
                return i