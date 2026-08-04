class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curr_alt = 0
        max_alt = 0
        for g in gain:
            curr_alt += g
            if max_alt < curr_alt:
                max_alt = curr_alt
        return max_alt