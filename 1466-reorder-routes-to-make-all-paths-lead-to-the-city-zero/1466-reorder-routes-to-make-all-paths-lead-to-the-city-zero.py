class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u , v in connections:
            adj[u].append((v , 1))
            adj[v].append((u , 0))
        self.change_count = 0
        visited = [False] * n

        def dfs(city : int):
            visited[city] = True
            for neighbour , cost in adj[city]:
                if not visited[neighbour]:
                    self.change_count += cost
                    dfs(neighbour)
        dfs(0)
        return self.change_count