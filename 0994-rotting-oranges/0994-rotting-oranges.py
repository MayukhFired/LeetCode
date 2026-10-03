class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        rows , cols = len(grid) ,len(grid[0])
        queue = deque()
        fresh = 0
        minute = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r , c))
                elif grid[r][c] == 1:
                    fresh += 1
        if fresh == 0:
            return 0
        directions = [(1 , 0) , (-1 , 0) , (0 , 1) , (0 , -1)]

        while queue and fresh > 0:
            minute += 1
            for _ in range(len(queue)):
                r , c = queue.popleft()
                for dr , dc in directions:
                    row , col = r + dr , c + dc
                    if 0 <= row < rows and 0 <=col < cols and grid[row][col] == 1:
                        grid[row][col] = 2
                        fresh -= 1
                        queue.append((row , col))
        return minute if fresh == 0 else -1