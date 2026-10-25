class Solution:
# 1----------------------------------------------------------------------------------------------------------------1
    # def bfs(self , x: int , y: int , m: int , n: int , grid: List[List[int]] , visit: List[List[bool]]) -> bool:
    #     q = deque([(x , y)])
    #     visit[x][y] = True
    #     is_closed = True

    #     dirx = [0 , 1 , 0 , -1]
    #     diry = [-1 , 0 , 1 , 0]

    #     while q:
    #         x , y = q.popleft()

    #         for i in range(4):
    #             r , c = x + dirx[i] , y + diry[i]
    #             if r < 0 or r >= m or c < 0 or c >= n:
    #                 is_closed = False
    #             elif grid[r][c] == 0 and not visit[r][c]:
    #                 q.append((r , c))
    #                 visit[r][c] = True
    #     return is_closed
# 1--------------------------------------------------------------------------------------------------------------1

    def closedIsland(self, grid: list[list[int]]) -> int:
    # 1----------------------------------------------------------------------1
        # m = len(grid)
        # n = len(grid[0])
        # visit = [[False] * n for _ in range(m)]
        # count = 0

        # for i in range(m):
        #     for j in range(n):
        #         if grid[i][j] == 0 and not visit[i][j] and self.bfs(i , j , m , n , grid , visit):
        #             count += 1
        # return count
    # 1----------------------------------------------------------------------1
        m = len(grid)
        n = len(grid[0])
        def floodfill(r: int , c: int , m: int , n: int , grid :list[list[int]]):
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != 0:
                return
            
            grid[r][c] = 1

            floodfill(r + 1 , c , m , n , grid)
            floodfill(r - 1 , c , m , n , grid)
            floodfill(r , c + 1 , m , n , grid)
            floodfill(r , c - 1 , m , n , grid)
        
        for j in range(n):
            if grid[0][j] == 0:
                floodfill(0 , j , m , n , grid)
            if grid[m - 1][j] == 0:
                floodfill(m - 1 , j , m , n , grid)
        
        for i in range(m):
            if grid[i][0] == 0:
                floodfill(i , 0 , m , n , grid)
            if grid[i][n - 1] == 0:
                floodfill(i , n - 1 , m , n , grid)
        
        count = 0
        for i in range(1 , m - 1):
            for j in range(1 , n - 1):
                if grid[i][j] == 0:
                    count += 1
                    floodfill(i , j , m , n, grid)
        return count