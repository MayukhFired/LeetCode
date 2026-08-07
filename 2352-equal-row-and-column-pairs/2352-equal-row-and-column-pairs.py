#Brute force solution of the problem
# class Solution:
#     def equalPairs(self, grid: List[List[int]]) -> int:
#         count = 0
#         n = len(grid)
#         for r in range(n):
#             for c in range(n):
#                 is_equal = True
#                 for i in range(n):
#                     if grid[r][i] != grid[i][c]:
#                         is_equal = False
#                 count += is_equal
#         return count

#Better approach
# class Solution:
#     def equalPairs(self, grid: List[List[int]]) -> int:
#         BASE = 131
#         MOD = 1_000_000_007
#         n = len(grid)
#         row_hashes = [0] * n
#         col_hashes = [0] * n
#         for i in range(n):
#             RowH = 0
#             ColH = 0
#             for j in range(n):
#                 RowH = (RowH * BASE + grid[i][j]) % MOD
#                 ColH = (ColH * BASE + grid[j][i]) % MOD
#             row_hashes[i] = RowH
#             col_hashes[i] = ColH
#         count = 0
#         for k in range(n):
#             for m in range(n):
#                 if row_hashes[k] == col_hashes[m]:
#                     count += 1
#         return count

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row_counts = Counter(tuple(row) for row in grid)
        return sum(row_counts[col] for col in zip(*grid))