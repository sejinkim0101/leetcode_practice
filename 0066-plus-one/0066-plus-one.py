from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1  # Initialize carry to 1 for the "+1" operation
        result = [0] * len(digits)  # Initialize result list with zeros

        for i in range(len(digits) - 1, -1, -1):
            _sum = digits[i] + carry
            result[i] = _sum % 10  # Store the current digit
            carry = _sum // 10  # Update carry for next calculation

        # If carry is left, place it in the first position
        if carry:
            result.insert(0, 1)

        return result
