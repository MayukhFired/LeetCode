class Solution:
    def arrayNesting(self, nums: list[int]) -> int:
        n = len(nums)
        visited = [False] * n
        ans = 0

        for i in range(n):
            if visited[i]:
                continue
            curr = i
            count = 0
            while not visited[curr]:
                visited[curr] = True
                curr = nums[curr]
                count += 1
            ans = max(ans , count)
        return ans