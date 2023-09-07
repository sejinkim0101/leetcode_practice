#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // Initialize carry to 1 as we're adding 1 to the number
    int carry = 1;
    
    // Create a result array with one extra space to handle overflow
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;  // Store the current digit
        carry = sum / 10;  // Update carry for next calculation
    }
    
    // If carry is left, place it in the first position
    if (carry) {
        result[0] = 1;
        *returnSize = digitsSize + 1;  // Update the size of the array
        return result;
    }
    
    // If no carry is left, we can ignore the first position
    *returnSize = digitsSize;
    return result + 1;
}
