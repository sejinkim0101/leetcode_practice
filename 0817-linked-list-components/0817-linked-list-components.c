#include <stdbool.h>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    // Create a hash table for nums
    bool num_set[10001] = {false};
    for (int i = 0; i < numsSize; ++i) {
        num_set[nums[i]] = true;
    }
    
    // Initialize variables
    int count = 0;
    bool connected = false;
    
    // Traverse the linked list
    while (head) {
        // If the current value is in nums
        if (num_set[head->val]) {
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
