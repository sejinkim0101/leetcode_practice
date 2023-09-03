#include <unordered_map>

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        std::unordered_map<int, ListNode*> prefix_sum = {{0, dummy}};
        int sum_val = 0;
        
        // First pass to fill the prefix sum table
        while (head) {
            sum_val += head->val;
            prefix_sum[sum_val] = head;
            head = head->next;
        }
        
        // Second pass to remove zero-sum sequences
        head = dummy;
        sum_val = 0;
        while (head) {
            sum_val += head->val;
            head->next = prefix_sum[sum_val]->next;
            head = head->next;
        }
        
        return dummy->next;
    }
};
