class Solution:
    def countCommas(self, n: int) -> int:
        com = 0
        for i in range(n + 1):
            if i > 999:
                com += 1
        return com