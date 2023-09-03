#include <unordered_set>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        // Convert nums to an unordered_set for O(1) look-up
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Initialize variables
        int count = 0;
        bool connected = false;
        
        // Traverse the linked list
        while (head) {
            // If the current value is in nums
            if (num_set.find(head->val) != num_set.end()) {
                // If not already connected, increment the count
                if (!connected) {
                    ++count;
                }
                // Mark as connected
                connected = true;
            } else {
                // Mark as not connected
                connected = false;
            }
            
            // Move to the next node
            head = head->next;
        }
        
        return count;
    }
};
