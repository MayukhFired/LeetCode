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

    # 2------------------------------------------------------------------------------------------------2
        # count = 0
        # m = len(grid)
        # n = len(grid[0])
        # rowCounts = [0] * len(grid)
        # colCounts = [0] * len(grid[0])

        # for row in range(m):
        #     for col in range(n):
        #         if grid[row][col] == 1:
        #             rowCounts[row] += 1
        #             colCounts[col] += 1
        
        # for row in range(m):
        #     for col in range(n):
        #         if grid[row][col] == 1:
        #             if rowCounts[row] > 1 or colCounts[col] > 1:
        #                 count += 1
        # return count
    # 2------------------------------------------------------------------------------------------------2

    # 3------------------------------------------------------------------------------------------------3
        # count = 0
        # m = len(grid)
        # n = len(grid[0])
        # colCount = [0] * n
        # InRow = [-1] * m

        # for row in range(m):
        #     countRow = 0
        #     for col in range(n):
        #         if grid[row][col]:
        #             count += 1
        #             countRow += 1
        #             colCount[col] += 1
        #             if countRow == 1:
        #                 InRow[row] = col
        #             else:
        #                 InRow[row] = -1
        
        # for row in range(m):
        #     col = InRow[row]
        #     if col != -1 and colCount[col] == 1:
        #         count -= 1
        
        # return count
    # 3---------------------------------------------------------------------------------------------3
        count = 0
        rows = len(grid)
        cols = len(grid[0])

        for rowIndex in range(rows):
            rowCounts = 0
            serverIndex = -1
            for colIndex in range(cols):
                if grid[rowIndex][colIndex]:
                    if rowCounts == 0:
                        serverIndex = colIndex
                    rowCounts += 1
            can = (rowCounts != 1)

            if not can:
                for i in range(rows):
                    if i != rowIndex and grid[i][serverIndex] == 1:
                        can = True
                        break
            if can:
                count += rowCounts
        return count