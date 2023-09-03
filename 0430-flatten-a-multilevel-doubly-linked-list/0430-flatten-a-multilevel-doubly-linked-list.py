"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head

        # Initialize stack and push the head node
        stack = [head]
        prev = Node(0)
        
        while stack:
            # Pop a node from the stack
            curr = stack.pop()
            
            # Link previous node to current node
            prev.next = curr
            curr.prev = prev
            
            # If current node has a next node, push it to the stack
            if curr.next:
                stack.append(curr.next)
            
            # If current node has a child, push it to the stack
            if curr.child:
                stack.append(curr.child)
                # Detach the child
                curr.child = None
            
            # Move the prev pointer to the current node
            prev = curr
        
        # Detach the pseudo head node and return the flattened list
        head.prev = None
        return head