class Solution:
    def smallestPalindrome(self, s: str) -> str:
        chars = list(s)
        n = len(s)
        mid = n // 2
        chars[0:mid] = sorted(chars[0:mid])
        for i in range(mid):
            chars[n - 1 - i] = chars[i]
        return "".join(chars)