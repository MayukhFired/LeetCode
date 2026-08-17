class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = 0
        for i in range(len(piles)):
            right = max(right , piles[i])
        while left < right:
            mid = left + (right - left) // 2
            hours = 0
            for i in range(len(piles)):
                hours += (piles[i] + mid - 1) // mid
            if hours <= h:
                right = mid
            else:
                left = mid + 1
        return left