from typing import List, Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        # Convert nums to a set for O(1) look-up
        num_set = set(nums)
        
        # Initialize variables
        count = 0
        connected = False
        
        # Traverse the linked list
        while head:
            # If the current value is in nums
            if head.val in num_set:
                # If not already connected, increment the count
                if not connected:
                    count += 1
                # Mark as connected
                connected = True
            else:
                # Mark as not connected
                connected = False
            
            # Move to the next node
            head = head.next
        
        return count
