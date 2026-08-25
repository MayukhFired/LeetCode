# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self , root: TreeNode , key: int) -> TreeNode:
        if not root:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left , key)
        elif key > root.val:
            root.right = self.deleteNode(root.right , key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            else:
                s = self.findMin(root.right)
                root.val = s.val
                root.right = self.deleteNode(root.right , s.val)
        return root
    def findMin(self , node: TreeNode) -> TreeNode:
        current = node
        while current.left:
            current = current.left
        return current