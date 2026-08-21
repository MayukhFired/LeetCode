1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
9        prefix_sum = {0 : 1}
10        def dfs(node , current_sum):
11            if not node:
12                return 0
13            current_sum += node.val
14            path_count = prefix_sum.get(current_sum - targetSum , 0)
15            prefix_sum[current_sum] = prefix_sum.get(current_sum , 0) + 1
16
17            path_count += dfs(node.left , current_sum)
18            path_count += dfs(node.right , current_sum)
19            prefix_sum[current_sum] -= 1
20            return path_count
21        return dfs(root , 0)