from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node to assist in edge cases
        dummy = ListNode(0)
        dummy.next = head
        # Hash table to store the prefix sum and corresponding node
        prefix_sum = {0: dummy}
        sum_val = 0
        
        # First pass to fill the prefix sum table
        while head:
            sum_val += head.val
            prefix_sum[sum_val] = head
            head = head.next
            
        # Second pass to remove zero-sum sequences
        head = dummy
        sum_val = 0
        while head:
            sum_val += head.val
            head.next = prefix_sum[sum_val].next
            head = head.next
            
        return dummy.next
