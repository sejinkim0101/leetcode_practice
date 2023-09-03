#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // Initialize the return size and result array
    *returnSize = k;
    struct ListNode** res = malloc(k * sizeof(struct ListNode*));
    
    // Calculate the length of the linked list
    int length = 0;
    struct ListNode* cur = head;
    while (cur) {
        length++;
        cur = cur->next;
    }
    
    // Calculate base size and extra elements
    int base_size = length / k;
    int extra = length % k;
    
    cur = head;
    for (int i = 0; i < k; i++) {
        // Initialize dummy node
        struct ListNode* dummy = malloc(sizeof(struct ListNode));
        struct ListNode* temp = dummy;
        
        // Add base_size number of nodes to the current part
        for (int j = 0; j < base_size; j++) {
            temp->next = cur;
            temp = temp->next;
            cur = cur->next;
        }
        
        // If extra elements remain, add one to this part
        if (extra > 0) {
            temp->next = cur;
            temp = temp->next;
            cur = cur->next;
            extra--;
        }
        
        // Terminate the current part
        if (temp) {
            temp->next = NULL;
        }
        
        // Store the current part into the result array
        res[i] = dummy->next;
        free(dummy);
    }
    
    return res;
}
