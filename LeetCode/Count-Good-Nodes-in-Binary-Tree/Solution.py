1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def goodNodes(self, root: TreeNode) -> int:
9        def dfs(node , max_so_far):
10            if not node:
11                return 0
12            is_good = 1 if node.val >= max_so_far else 0
13            max_so_far = max(max_so_far , node.val)
14            left_good = dfs(node.left , max_so_far)
15            right_good = dfs(node.right , max_so_far)
16            return is_good + left_good + right_good
17        return dfs(root , root.val)