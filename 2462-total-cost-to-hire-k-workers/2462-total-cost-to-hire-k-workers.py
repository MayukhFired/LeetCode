class Solution:
    def totalCost(self, costs: list[int], k: int, candidates: int) -> int:
        n = len(costs)
        head = []
        tail = []

        i = 0
        j = n - 1
        total_cost = 0

        for _ in range(k):
            while len(head) < candidates and i <= j:
                heapq.heappush(head , (costs[i] , i))
                i += 1
            while len(tail) < candidates and i <= j:
                heapq.heappush(tail , (costs[j] , j))
                j -= 1

            if head and tail:
                if head[0] <= tail[0]:
                    cost , idx = heapq.heappop(head)
                    total_cost += cost
                else:
                    cost , idx = heapq.heappop(tail)
                    total_cost += cost
            elif head:
                cost , idx = heapq.heappop(head)
                total_cost += cost
            elif tail:
                cost , idx = heapq.heappop(tail)
                total_cost += cost
        return total_cost
