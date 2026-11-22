class Solution:
    def checkString(self, s: str) -> bool:
        n = len(s)
        last_a = -1
        first_b = n

        for i in range(n):
            if s[i] == 'a':
                last_a = max(last_a , i)
            else:
                first_b = min(first_b , i)

        return last_a < first_b