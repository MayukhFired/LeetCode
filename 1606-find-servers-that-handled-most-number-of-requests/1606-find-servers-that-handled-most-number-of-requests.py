class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        busy = []
        available = SortedSet(range(k))
        requests_handled = [0] * k

        for i , arr_time in enumerate(arrival):
            while busy and busy[0][0] <= arr_time:
                _ , finished_server = heapq.heappop(busy)
                available.add(finished_server)

            if not available:
                continue
            target = i % k
            idx = available.bisect_left(target)
            if idx == len(available):
                idx = 0

            server_id = available[idx]
            available.remove(server_id)
            heapq.heappush(busy , (arr_time + load[i] , server_id))
            requests_handled[server_id] += 1

        max_handled = max(requests_handled)

        return [
            server_id
            for server_id , count in enumerate(requests_handled)
            if count == max_handled
        ]