1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, x):
4#         self.val = x
5#         self.left = None
6#         self.right = None
7
8class Solution:
9    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
10        if not root or root == p or root == q: return root
11        left = self.lowestCommonAncestor(root.left , p , q)
12        right = self.lowestCommonAncestor(root.right , p , q)
13        return root if left and right else (left or right)