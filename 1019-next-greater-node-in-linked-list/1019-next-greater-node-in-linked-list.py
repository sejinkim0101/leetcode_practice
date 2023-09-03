from typing import List, Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        # Initialize an empty stack and an empty result list
        stack, res = [], []
        
        # Traverse the linked list
        while head:
            # Append the node value to the result list
            res.append(0)
            
            # While the stack is not empty and the top element is smaller than the current value
            while stack and stack[-1][1] < head.val:
                # Update the corresponding index in the result list
                idx, _ = stack.pop()
                res[idx] = head.val
                
            # Append the index and value to the stack
            stack.append((len(res) - 1, head.val))
            
            # Move to the next node
            head = head.next
            
        return res
