// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
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
};
