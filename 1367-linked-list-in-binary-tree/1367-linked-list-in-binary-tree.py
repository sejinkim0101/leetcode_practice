# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        # Helper function to check the path
        def checkPath(head, node):
            if not head:
                return True
            if not node:
                return False
            if head.val != node.val:
                return False
            return checkPath(head.next, node.left) or checkPath(head.next, node.right)
        
        # Base case
        if not root:
            return False
        # Check if a path starts from the current node or try the next node
        return checkPath(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
