class Solution:
    def countNegatives(self, grid: list[list[int]]) -> int:
        # count = 0
        # for i in range(len(grid)):
        #     for j in range(len(grid[i])):
        #         if grid[i][j] < 0:
        #             count += len(grid[i]) - j
        #             break
        # return count

        count = 0
        i = len(grid) - 1
        j = 0
        n = len(grid[0])

        while i >= 0 and j < n:
            if grid[i][j] >= 0:
                j += 1
            else:
                count += n - j
                i -= 1
        return count