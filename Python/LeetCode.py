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
    
#Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
    
class Solution:
    def reverseWords(self, s: str) -> str:
        def reverseWord(word):
            return word[::-1] #This is used to reverse items in a list
    
        s_split = s.split(' ')
        s_reverse = [reverseWord(i) for i in s_split]
        return ' '.join(s_reverse)

'''
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its minimum depth = 2.

'''
    
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # Corner Case.Should never be hit unless the code is  
        # called on root = NULL 
        if root is None: 
            return 0 
        
        # Base Case : Leaf node.This acoounts for height = 1 
        if root.left is None and root.right is None: 
            return 1
        
        # If left subtree is Null, recur for right subtree 
        if root.left is None: 
            return self.minDepth(root.right)+1
        
        # If right subtree is Null , recur for left subtree 
        if root.right is None: 
            return self.minDepth(root.left) +1 
        
        return min(self.minDepth(root.left), self.minDepth(root.right))+1
