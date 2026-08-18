class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        counts = Counter(nums)
        if k == 1:
            uniques = [x for x , c in counts.items() if c == 1]
            return max(uniques) if uniques else -1
        if k == n:
            return max(nums)
        ans = -1
        if counts[nums[0]] == 1:
            ans = max(ans , nums[0])
        if counts[nums[-1]] == 1:
            ans = max(ans , nums[-1])
        return ans