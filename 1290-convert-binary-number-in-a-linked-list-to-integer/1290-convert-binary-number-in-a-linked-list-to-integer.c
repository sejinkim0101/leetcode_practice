// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

int getDecimalValue(struct ListNode* head) {
    // Initialize result to 0
    int result = 0;
    
    // Traverse the linked list
    while (head) {
        // Shift the current result to make space for the next bit
        result <<= 1;
        // Add the current bit
        result += head->val;
        // Move to the next node
        head = head->next;
    }
    
    return result;
}
