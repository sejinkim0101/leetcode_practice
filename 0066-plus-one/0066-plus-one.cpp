#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;  // Initialize carry to 1 for the "+1" operation
        std::vector<int> result(digits.size(), 0);  // Initialize result vector with zeros

        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result[i] = sum % 10;  // Store the current digit
            carry = sum / 10;  // Update carry for next calculation
        }

        // If carry is left, place it in the first position
        if (carry) {
            result.insert(result.begin(), 1);
        }

        return result;
    }
};
