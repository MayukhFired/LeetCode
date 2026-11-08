class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
    # 1----------------------------------------------------------------------------1
        # count = 0
        # m = len(grid)
        # n = len(grid[0])

        # for row in range(m):
        #     for col in range(n):
        #         if grid[row][col] == 1:
        #             can = False
        #             for otherCol in range(n):
        #                 if otherCol != col and grid[row][otherCol] == 1:
        #                     can = True
        #                     break
        #             if can:
        #                 count += 1
        #             else:
        #                 for otherRow in range(m):
        #                     if otherRow != row and grid[otherRow][col] == 1:
        #                         can = True
        #                         break
        #                 if can:
        #                     count += 1
        # return count
    # 1-------------------------------------------------------------------------------------------------1

        count = 0
        m = len(grid)
        n = len(grid[0])
        rowCounts = [0] * len(grid)
        colCounts = [0] * len(grid[0])

        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    rowCounts[row] += 1
                    colCounts[col] += 1
        
        for row in range(m):
            for col in range(n):
                if grid[row][col] == 1:
                    if rowCounts[row] > 1 or colCounts[col] > 1:
                        count += 1
        return count