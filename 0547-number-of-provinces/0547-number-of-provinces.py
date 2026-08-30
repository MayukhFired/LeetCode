class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(city : int):
            visited.add(city)
            for neighbour , connected in enumerate(isConnected[city]):
                if connected == 1 and neighbour not in visited:
                    dfs(neighbour)
        n = len(isConnected)
        visited = set()
        provinces = 0
        for i in range(n):
            if i not in visited:
                dfs(i)
                provinces += 1
        return provinces