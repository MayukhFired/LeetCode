class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(dict)
        for (src , dst) , val in zip(equations , values):
            graph[src][dst] = val
            graph[dst][src] = 1.0 / val
        def dfs(curr: str , target: str , visited: set) -> float:
            if curr not in graph or target not in graph:
                return -1.0
            if curr == target:
                return 1.0
            
            visited.add(curr)
            for neighbour , weight in graph[curr].items():
                if neighbour not in visited:
                    product = dfs(neighbour , target , visited)
                    if product != -1.0:
                        return weight * product
            return -1.0
        results = []
        for src , dst in queries:
            results.append(dfs(src , dst , set()))
        return results