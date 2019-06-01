#Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

class Solution:
    def toLowerCase(self, str: str) -> str:
        return str.lower()

#Invert Binary Tree.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        
        if root is None:
            return root
        
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        t = root.left
        root.left = root.right
        root.right = t
        
        return root

#Given an array A of distinct integers sorted in ascending order, return the smallest index i that satisfies A[i] == i.  
#Return -1 if no such i exists.    
    
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        length = len(A)
        for i in range(length): 
            if A[i] == i: 
                return i 
        return -1
    
