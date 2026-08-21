class Solution:
  def leafSimilar(self, root1, root2):
    iterator1 = self.leafsLTR(root1)
    iterator2 = self.leafsLTR(root2)
    return all(a == b for a, b in itertools.zip_longest(iterator1, iterator2))
  
  def leafsLTR(self, node):
    if node:
      if not node.left and not node.right:
        yield node.val
      yield from self.leafsLTR(node.left)
      yield from self.leafsLTR(node.right)