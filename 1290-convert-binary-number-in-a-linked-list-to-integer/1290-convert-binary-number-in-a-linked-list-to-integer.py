# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        # Initialize result to 0
        result = 0
        
        # Traverse the linked list
        while head:
            # Shift the current result to make space for the next bit
            result <<= 1
            # Add the current bit
            result += head.val
            # Move to the next node
            head = head.next
            
        return result
