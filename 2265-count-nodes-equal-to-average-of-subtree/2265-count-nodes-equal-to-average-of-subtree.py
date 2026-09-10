# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.count = 0
        def dfs(node):
            if not node:
                return 0 , 0
            lval , lcount = dfs(node.left)
            rval , rcount = dfs(node.right)

            nodeVal = lval + rval + node.val
            nodeCount = lcount + rcount + 1

            if nodeVal // nodeCount == node.val: self.count += 1
            return nodeVal , nodeCount
        dfs(root)
        return self.count
