class Solution:
    def numTrees(self, n: int) -> int:
        uniqueTrees = [1] * (n + 1)

        for nodes in range(2 , n + 1):
            total = 0
            for root in range(1 , nodes + 1):
                total += uniqueTrees[root - 1] * uniqueTrees[nodes - root]
            uniqueTrees[nodes] = total
        return uniqueTrees[n]