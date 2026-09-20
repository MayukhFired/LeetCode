class Solution:
    def reverseDegree(self, s: str) -> int:
        c = 0
        for i , ch in enumerate(s , start = 1):
            c += (26 - (ord(ch) - ord("a"))) * i
        return c
