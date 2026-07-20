class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        total = m * n
        k = k % total
        result = [[0] * n for _ in range(m)]

        for r in range(m):
            for c in range(n):
                flat_index = r *n + c
                new_flat_index = (flat_index + k) % total
                new_r = new_flat_index // n
                new_c = new_flat_index % n
                result[new_r][new_c] = grid[r][c]

        return result