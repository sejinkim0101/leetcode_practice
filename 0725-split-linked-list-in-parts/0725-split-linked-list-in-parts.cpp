/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Initialize result vector
        std::vector<ListNode*> res(k, nullptr);
        
        // Calculate the length of the linked list
        int length = 0;
        ListNode* cur = head;
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
            ListNode dummy;
            ListNode* temp = &dummy;
            
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
                temp->next = nullptr;
            }
            
            // Store the current part into the result vector
            res[i] = dummy.next;
        }
        
        return res;
    }
};