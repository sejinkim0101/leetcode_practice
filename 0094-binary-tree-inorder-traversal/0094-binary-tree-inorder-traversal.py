# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        ## sol1) recursive 
#         result = [] # to make it easier
        
#         def inorder(root):
#             if not root: # base case
#                 return
            
#             # inorder ordering (left - itself - right)
#             inorder(root.left)
#             result.append(root.val)
#             inorder(root.right)
        
#         inorder(root)
#         return result
        

        ## sol2) iterative ## stack structure
        res = []
        stack = []
        cur = root
        
        while cur or stack: ## important to think this line 
            while cur:
                stack.append(cur)
                cur = cur.left
            # cur will be pointing at null at this point
            
            cur = stack.pop() # reasssign cur
            res.append(cur.val) 
            cur = cur.right ## shift to the right after appending to res
        
        return res
        
        
        
        #참고) https://www.youtube.com/watch?v=g_S5WuasWUE