class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
    # 1----------------------------------------------------------------------1
        # MOD = 10**9 + 7
        # m , n = len(grid) , len(grid[0])

        # f = [[[0 , 0] for _ in range(n)] for _ in range(m)]
        # f[0][0][0] = 1

        # for i in range(m):
        #     for j in range(n):
        #         if i > 0:
        #             if grid[i - 1][j] == 0:
        #                 f[i][j][0] = f[i - 1][j][0] + f[i - 1][j][1]
        #             else:
        #                 f[i][j][0] = f[i - 1][j][1]
        #             f[i][j][0] %= MOD
        #         if j > 0:
        #             if grid[i][j - 1] == 0:
        #                 f[i][j][1] = f[i][j - 1][0] + f[i][j - 1][1]
        #             else:
        #                 f[i][j][1] = f[i][j - 1][0]
        #             f[i][j][1] %= MOD
        # return (f[m - 1][n - 1][0] + f[m - 1][n - 1][1]) % MOD
    # 1-----------------------------------------------------------------------1

        m , n = len(grid) , len(grid[0])
        currRow = [0] * n
        currRow[0] = 1
        for row in grid:
            prevRow , currRow , prevCell = currRow , [0] * n , 0
            for idx , p in enumerate(prevRow): 
                if row[idx] == 0:
                    currRow[idx] , prevCell = prevCell + p , prevCell + p
                else:
                    currRow[idx] , prevCell = prevCell , p
        return currRow[-1] % 1_000_000_007