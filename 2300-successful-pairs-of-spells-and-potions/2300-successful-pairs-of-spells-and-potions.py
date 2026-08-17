class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(potions)
        result = []
        for spell in spells:
            required = (success + spell - 1) // spell
            left = 0
            right = n
            while left < right:
                mid = left + (right - left) // 2
                if potions[mid] >= required:
                    right = mid
                else:
                    left = mid + 1
            result.append(n - left)
        return result