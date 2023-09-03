from typing import List, Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        # Initialize result array
        res = [None] * k
        
        # Find length of the linked list
        length = 0
        cur = head
        while cur:
            length += 1
            cur = cur.next
        
        # Calculate base size and extra elements to be distributed
        base_size = length // k
        extra = length % k
        
        cur = head
        for i in range(k):
            # Initialize dummy node
            dummy = ListNode()
            temp = dummy
            
            # Add base_size number of nodes to the current part
            for _ in range(base_size):
                temp.next = cur
                temp = temp.next
                cur = cur.next
            
            # If extra elements remain, add one to this part
            if extra > 0:
                temp.next = cur
                temp = temp.next
                cur = cur.next
                extra -= 1
            
            # Terminate the current part
            if temp:
                temp.next = None
            
            # Store the current part into the result array
            res[i] = dummy.next
        
        return res
