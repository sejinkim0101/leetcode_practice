# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
                
        # Base case: if the root is None, or if the root is one of p or q, return the root.
        if root in (None, p, q):
            return root
        
        # Recursive case: traverse the left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        # If both p and q are found in left and right subtrees of the current node
        # then the node itself is their LCA.
        if left and right:
            return root
        
        # Otherwise, if one of them is found on left or right subtree
        # then this node is not LCA, return either one of them.
        return left or right