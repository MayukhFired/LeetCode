class Solution:
    def findGCD(self, nums: List[int]) -> int:
      M = max(nums)
      m = min(nums)
      return math.gcd(M , m)  