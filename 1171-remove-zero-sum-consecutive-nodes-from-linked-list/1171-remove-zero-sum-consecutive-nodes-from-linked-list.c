#include <stdlib.h>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    // Calculate the maximum and minimum sum to determine array size
    int max_sum = 0, min_sum = 0, sum = 0;
    struct ListNode* current = head;
    while (current) {
        sum += current->val;
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (sum < min_sum) {
            min_sum = sum;
        }
        current = current->next;
    }
    
    // Initialize prefix sum array and set the base index
    struct ListNode* prefix_sum[max_sum - min_sum + 1];
    for (int i = 0; i < max_sum - min_sum + 1; ++i) {
        prefix_sum[i] = NULL;
    }
    int base_index = -min_sum; // Offset to handle negative sums
    
    // Dummy node
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    prefix_sum[base_index] = &dummy;
    
    // First pass to populate prefix sum array
    sum = 0;
    current = head;
    while (current) {
        sum += current->val;
        prefix_sum[sum + base_index] = current;
        current = current->next;
    }
    
    // Second pass to remove zero-sum sequences
    sum = 0;
    current = &dummy;
    while (current) {
        sum += current->val;
        current->next = prefix_sum[sum + base_index]->next;
        current = current->next;
    }
    
    return dummy.next;
}
