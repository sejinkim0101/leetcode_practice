// SOL1) - GPT4

#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> countMap; // Declare a hash map to store the count of each number in the array
        int operations = 0; // Initialize a variable to store the maximum number of operations
        
        // Iterate through the nums array
        for(int num : nums) {
            int complement = k - num; // Calculate the complement, i.e., the value that should be added to num to get k
            
            // Check if the complement exists in the hash map
            if(countMap[complement] > 0) {
                // If the complement exists, decrement its count in the hash map, and increment the operations counter
                countMap[complement]--;
                operations++;
            } else {
                // If the complement doesn't exist, increment the count of the current number in the hash map
                countMap[num]++;
            }
        }
        
        // Return the total number of operations
        return operations;
    }
};




// SOL2) - Leetcode Discussion 

// https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/2005922/Going-from-O(N2)-greater-O(NlogN)-greater-O(N)-%2B-MEME

// class Solution {
//     public int maxOperations(int[] nums, int k) {
//         Arrays.sort(nums);
//         int count = 0;
//         int i = 0;
//         int j = nums.length - 1;
//         while(i < j){
//             int sum = nums[i] + nums[j];
//             if(sum == k) {
//                 count++;
//                 i++;
//                 j--;
//             }
//             else if(sum > k) j--;
//             else i++;
//         }
//         return count;
//     }
// }